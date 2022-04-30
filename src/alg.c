/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 18:21:23 by ccottin           #+#    #+#             */
/*   Updated: 2022/04/30 20:48:34 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_last(t_nbr *stack)
{
	t_nbr	*temp;

	temp = stack;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp->ord);
}

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
	printf("\n");
	printf("\n");
}

int	check_rr(t_data *data)
{
	int	last_a;
	int	last_b;

	if (data->stack_a != NULL)
		last_a = get_last(data->stack_a);
	if (data->stack_b != NULL)
		last_b = get_last(data->stack_b);
	if (data->stack_b && data->stack_b->next && data->stack_a && data->stack_a->next
	&& data->stack_a->ord > last_a && data->stack_b->ord < last_b)
		rr(data);
	else if (data->stack_b && data->stack_b->next
		&& data->stack_b->ord < last_b)
		rb(data, 0);
	else if (data->stack_a && data->stack_a->next
		&& data->stack_a->ord > last_a)
		ra(data, 0);
	else
		return (0);
	return (1);
}

/*void	check_rrr(t_data *data)
{
	int	last_a;
	int	last_b;

	if (data->stack_a != NULL)
		last_a = get_last(data->stack_a);
	if (data->stack_b != NULL)
		last_b = get_last(data->stack_b);
	if (data->stack_b && data->stack_b->next && data->stack_a && data->stack_a->next
	&& data->stack_a->ord > last_a && data->stack_b->ord < last_b)
		rrr(data);
	else if (data->stack_b && data->stack_b->next
		&& data->stack_b->ord < last_b)
		rrb(data, 0);
	else if (data->stack_a && data->stack_a->next
		&& data->stack_a->ord > last_a)
		rra(data, 0);
}*/

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




void	algo(t_data *data)
{
	int	mid;
	int	i;
	int	mark;

//	a voir si on fait pas un tier
	mid = data->total / 2;
	mark = get_last(data->stack_a);
	i = -1;
	while (i != mark)
	{
		printf("%d, %d\n", i, mark);
		check_ss(data);
		i = data->stack_a->ord;
		if (data->stack_a->ord < mid)
			pb(data);
		else
		{
			if (check_rr(data) == 0)
				ra(data, 0);
		}
/*		{
			if (check_rr(data) == 0)
			{
				check_rrr(data);
				check_ss(data);
			}
		}*/
		printf("%d, %d\n", i, mark);
		ft_testc(data);
	}

	ft_testc(data);
}
