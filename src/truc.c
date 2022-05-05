/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 17:31:57 by ccottin           #+#    #+#             */
/*   Updated: 2022/05/05 16:58:28 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	phase_two(t_data *data, int max)
{
	int	i;
	int	temp;

	i = 0;
	temp = get_last(data->stack_a);
	while (data->stack_a->ord != temp
		&& check_still_nb(data->stack_a, max) == 1)
	{
		if (data->stack_a->ord < max)
		{
			pb(data);
			i++;
		}
		else
			ra(data, 0);
	}
	if (data->stack_a->ord < max)
		pb(data);
	return (i);
}

void	phase_three(t_data *data)
{
	int	small;
	int	move;

	move = 0;
	while (sorted(data->stack_a) != -1)
	{
		small = find_smallest(data->stack_a);
		if (count_move(data->stack_a, small) < 0)
			move += do_rra(data, small);
		else
			move += do_ra(data, small);
		move++;
	}
	while (move != 0)
	{
		pa(data);
		move--;
	}
}

void	phase_four(t_data *data, int size)
{
	int	big;
	int	move;

	move = 0;
	big = size + 1;
	while (big > size)
	{
		big = find_biggest(data->stack_b);
		if (count_move(data->stack_b, big) < 0)
			move += do_rrb(data, big);
		else
			move += do_rb(data, big);
		move++;
	}
	while (move != 0)
	{
		pb(data);
		move--;
	}
}

void	phase_five(t_data *data, int size)
{
	int	i;

	i = 0;
	while (data->stack_b->ord > size)
	{
		if (i == 0)
			put_biggest(data);
		if (data->stack_a->ord - 1 == get_last(data->stack_a)
			|| data->stack_a->ord - 1 == get_s_last(data->stack_a))
		{
			rra(data, 0);
			if (data->stack_a->ord + 1 == get_last(data->stack_a))
				rra(data, 0);
		}
		if (data->stack_a->next->ord > data->stack_a->ord - 2)
			check_ss(data);
		if (data->stack_a->ord - 1 == data->stack_b->ord
			|| data->stack_a->ord - 1 == data->stack_b->next->ord)
		{
			pa(data);
			if (data->stack_a->ord + 1 == data->stack_b->ord)
				pa(data);
		}
		i++;
	}
}

void	truc(t_data *data)
{
	int	size;
	int	i;

	i = 0;
	size = data->total / 3;
	while (i != size)
	{
		pb(data);
		if (data->stack_b->ord < size)
			rb(data, 0);
		i++;
	}
	i = phase_two(data, size);
	while (data->stack_b->ord < size)
		rb(data, 0);
	phase_three(data);
	phase_four(data, size);
	phase_five(data, size);
	phase_six(data);
}
