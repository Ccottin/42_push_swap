/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:19:43 by ccottin           #+#    #+#             */
/*   Updated: 2022/04/26 14:34:48 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_sorted(t_data *data)
{
	t_nbr	*temp;
	int	i;

	temp = data->stack_a;
	i = 0;
	while (temp != NULL && i == temp->ord)
	{
		temp = temp->next;
		i++;
	}
	if (i == data->total)
		return (1);
	return (0);
}

void	sort_3(t_data *data)
{
	if (data->stack_a->ord == 0)
	{
		pb(data);
		sa(data, 0);
		pa(data);
	}
	else if (data->stack_a->ord == 2 && data->stack_a->next->ord == 1)
	{
		ra(data, 0);
		sa(data, 0);
	}
	else if (data->stack_a->ord == 2 && data->stack_a->next->ord == 0)
		ra(data, 0);
	else if (data->stack_a->ord == 1 && data->stack_a->next->ord == 0)
		sa(data, 0);
	else if (data->stack_a->ord == 1 && data->stack_a->next->ord == 2)
		rra(data, 0);
}

/*pire cas ici = 3 4 2 1 il fait en tout 7 coups
 * en moyenne 6*/

void	sort_4(t_data *data)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if  (data->stack_a->ord == 0 || data->stack_a->ord == 1)
		{
			pb(data);
			i++;
		}
		else
			ra(data, 0);
	}
	if (data->stack_a->ord > data->stack_a->next->ord
		&& data->stack_b->ord < data->stack_b->next->ord)
		ss(data);
	else if (data->stack_a->ord > data->stack_a->next->ord)
		sa(data, 0);
	else if (data->stack_b->ord < data->stack_b->next->ord)
	       sb(data, 0);
	pa(data);
	pa(data);

}
/*
void	sort_5(t_data *data)
{
	
}*/

void	push_swap(t_data *data, char **av, int ac)
{
	ft_init(data, av, ac);
	t_nbr	*temp;
	temp = data->stack_a;
	while (temp != NULL)
	{
		printf("staka nb = %d ord = %d\n", temp->nb, temp->ord);
		temp = temp->next;
	}
	if (check_sorted(data) == 1)
		end(data);
	printf("total = %d\n", data->total);
	if (data->total == 2)
		sa(data, 0);
	else if (data->total == 3)
		sort_3(data);
	else if (data->total == 4)
		sort_4(data);
//	quick_sort(data);
//	bubble_sort(data);
	radix_sort(data);
	if (check_sorted(data) == 1)
		printf("%d : %s\n", data->temp.nb_move, data->temp.move);
//	t_nbr	*temp;	
//	pb(data);
//	pb(data);
//	pb(data);
//	pb(data);
	temp = data->stack_a;
	while (temp != NULL)
	{
		printf("staka nb = %d ord = %d\n", temp->nb, temp->ord);
		temp = temp->next;
	}
	temp = data->stack_b;
	while (temp != NULL)
	{
		printf("stakb nb = %d ord = %d\n", temp->nb, temp->ord);
		temp = temp->next;
	}
}
