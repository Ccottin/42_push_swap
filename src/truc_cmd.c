/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truc_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:20:22 by ccottin           #+#    #+#             */
/*   Updated: 2022/05/05 16:29:36 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	do_rb(t_data *data, int big)
{
	int	move;

	move = 0;
	while (data->stack_b->ord != big)
	{
		if (data->stack_b->ord == big + 1 || data->stack_b->ord == big - 1)
		{
			pa(data);
			move++;
		}
		rb(data, 0);
	}
	pa(data);
	return (move);
}

int	do_rrb(t_data *data, int big)
{
	int	move;

	move = 0;
	while (data->stack_b->ord != big)
	{
		if (data->stack_b->ord == big + 1 || data->stack_b->ord == big - 1)
		{
			pa(data);
			move++;
		}
		rrb(data, 0);
	}
	pa(data);
	return (move);
}

int	do_ra(t_data *data, int small)
{
	int	move;

	move = 0;
	while (data->stack_a->ord != small)
	{
		if (data->stack_a->ord == small + 1 || data->stack_a->ord == small - 1)
		{
			pb(data);
			move++;
		}
		ra(data, 0);
	}
	pb(data);
	return (move);
}

int	do_rra(t_data *data, int small)
{
	int	move;

	move = 0;
	while (data->stack_a->ord != small)
	{
		if (data->stack_a->ord == small + 1 || data->stack_a->ord == small - 1)
		{
			pb(data);
			move++;
		}
		rra(data, 0);
	}
	pb(data);
	return (move);
}

void	check_ss(t_data *data)
{
	if (data->stack_b && data->stack_b->next && data->stack_a
		&& data->stack_a->next
		&& data->stack_a->ord > data->stack_a->next->ord
		&& data->stack_b->ord < data->stack_b->next->ord)
		ss(data);
	else if (data->stack_b && data->stack_b->next
		&& data->stack_b->ord < data->stack_b->next->ord)
		sb(data, 0);
	else if (data->stack_a->ord > data->stack_a->next->ord)
		sa(data, 0);
}
