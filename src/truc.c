/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 17:31:57 by ccottin           #+#    #+#             */
/*   Updated: 2022/05/01 21:37:24 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_testc(t_data *data)
{
	t_nbr *temp;

	printf("\n");
	printf("\n");
	temp = data->stack_a;
	while (temp != NULL)
	{	
		printf("A nb = %s ord = %d\n", temp->bin, temp->ord);
		temp = temp->next;
	}
	printf("\n");
	temp = data->stack_b;
	while (temp != NULL)
	{
		printf("B nb = %s ord = %d\n", temp->bin, temp->ord);
		temp = temp->next;
	}
}

int	get_last(t_nbr *stack)
{
	t_nbr	*temp;

	temp = stack;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp->ord);
}

int	check_still_nb(t_nbr *stack, int max)
{
	t_nbr	*temp;

	temp = stack;
	while (temp->next != NULL)
	{
		if (temp->ord < max)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	phase_two(t_data *data, int max)
{
	int	i;
	int	temp;

	i = 0;
	temp = get_last(data->stack_a);
	while (data->stack_a->ord != temp && check_still_nb(data->stack_a, max) == 1)
	{
		if (data->stack_a->ord < max)
		{
			pb(data);
			i++;
		}
		else
			ra(data, 0);
	}
	return (i);
}

int	check_elem(t_nbr *b, int max)
{
	if (b->ord < max)
		return (1);
	return (0);
}
/*
int	get_closest(t_nbr *stack, int len, int top, int bot)
{
	t_nbr	*temp;
	int	i;
	int	j;

	temp = stack;
	i = 0;
	while (temp->ord != top)
	{
		temp = temp->next;
		i++;
	}
	j = i;
	while (temp->ord != bot)
	{
		temp = temp->next;
		j++;
	}
	j = len - j;
	if (j < i)
		return (-j);
	else
		return (i);
}

int	find_closest(t_nbr *stack, int max, int s)
{
	t_nbr	*temp;
	int	ref;
	int	i;
	int	j;

	ref = stack->ord;
	temp = stack;
	i = 0;
	while (i == 0)
	{
		if (temp->ord > ref - max / 6 && temp->ord < ref + max / 6 && s < 0)
		
			i = temp->ord;
		s--;
		temp = temp->next;
	}
	while (temp != NULL)
	 {
		if (temp->ord > ref - max / 6 && temp->ord < ref + max / 6)
			j = temp->ord;
		temp = temp->next;
	 }
	 return (get_closest(stack , ft_lstlen(stack), i, j));
}

void	phase_three(t_data *data, int max)
{
	int	move;
	int	i;

	i = 1;
	while (sorted(data->stack_a) != -1)
	{
		move = find_closest(data->stack_a, max, i);
		if (move > 0)
			ft_1(data, move);
		else if (move < 0)
			ft_2(data, move);
		ft_testc(data);
	}
	printf("move = %d\n", move);
}
*/
void	rotate_t_t(t_data *data, int top, int max)
{
/*	int	bot;
	t_nbr	*temp;

	temp = data->stack_b;
	bot = 0;
	while (temp != NULL)
	{
		if (temp->ord < max)
			bot++;
		temp = temp->next;
	}*/
	(void)top;
	while (data->stack_b->ord < max)
		rb(data, 0);
}

int	count_move(t_nbr *stack, int rank)
{
	int	i;
	int	total;
	t_nbr	*temp;

	i = 0;
	total = ft_lstlen(stack);
	temp = stack;
	while (temp->ord != rank)
	{
		temp = temp->next;
		i++;
	}
	if (i > total / 2)
		return (i - total - 1);
	return (i);
}

int	find_smallest(t_nbr *stack)
{
	t_nbr	*temp;
	int	small;

	temp = stack;
	small = 2147483647;
	while (temp != NULL)
	{
		if (small > temp->ord)
			small = temp->ord;
		temp = temp->next;
	}
	return (small);
}

int	sorted(t_nbr *stack)
{
	int	i;
	int	len;
	t_nbr	*temp;

	len = ft_lstlen(stack);
	i = 0;
	temp = stack;
	while (temp != NULL)
	{
		if (temp->next != NULL && temp->ord < temp->next->ord)
			i++;
		temp = temp->next;
	}
	if (i == len)
		return (-1);
	return (i);
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
//on peut opti en effectuant un petit tri de stack_a
void	re_phase_three(t_data *data)
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

int	find_biggest(t_nbr *stack)
{
	t_nbr	*temp;
	int	big;

	temp = stack;
	big = 0;
	while (temp != NULL)
	{
		if (big < temp->ord)
			big = temp->ord;
		temp = temp->next;
	}
	return (big);

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

void	check_ss(t_data *data)
{
	if (data->stack_b && data->stack_b->next && data->stack_a && data->stack_a->next
	&& data->stack_a->ord > data->stack_a->next->ord
	&& data->stack_b->ord < data->stack_b->next->ord)
		ss(data);
	else if (data->stack_b && data->stack_b->next
		&& data->stack_b->ord < data->stack_b->next->ord)
		sb(data, 0);
	else if (data->stack_a->ord > data->stack_a->next->ord)
		sa(data, 0);
}

void	phase_five(t_data *data, int size)
{
	int	last_a;
		int i = 0;
	while (data->stack_b->ord > size)
	{
		i++;
		printf("\n\nca passe %d\n", i);
		ft_testc(data);
		check_ss(data);
		last_a = get_last(data->stack_a);//go fix ton insertion
		while (data->stack_a->ord < data->stack_b->ord )
		{
			printf("%d, %d\n", data->stack_b->ord, last_a - 1);
			rra(data, 0);
			last_a = get_last(data->stack_a);
		}
		pa(data);
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
	rotate_t_t(data, i, size);
	ft_testc(data);
	//phase_three(data, size);
	re_phase_three(data);
	phase_four(data, size);
	ft_testc(data);
	phase_five(data, size);
	ft_testc(data);
}
