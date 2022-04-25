/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:55:14 by ccottin           #+#    #+#             */
/*   Updated: 2022/04/13 21:08:52 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
/*
int	find_pivot(t_data *data)
{
	t_nbr	*pivot;
	int	mid;

	pivot = data->stack_a;
	mid = data->total / 2;
	while (pivot->ord != mid)
		pivot = pivot->next;
	return (pivot);
}

peut être = diviser en deux grosses stack pour les quick sort chacune individuellement, la a = gros chffre ordre décroissant et la b petit chiffre ordre décroissant, puis faire un pa jusqu'a ce que ce soit goode? autre idée = le mur est dans b et c le seul élément? en attendant ra
*/

void	quick_sort(t_data *data)
{
	int	pivot;
	int	i;

	pivot = data->total / 2;
 	i = 0;
	while (i < data->total)
	{
		if (data->stack_a->ord < pivot)
			pb(data);
		else
			ra(data, 0);
	/*	if (data->stack_b->ord)
		{
			if (data->stack_a->ord > data->stack_a->next->ord && data->stack_b->ord < data->stack_b->next->ord)
				ss(data);
			else if (data->stack_a->ord > data->stack_a->next->ord)
				sa(data, 0);
			else if (data->stack_b->ord < data->stack_b->next->ord)
			       sb(data, 0);
		}*/
		i++;
	}
	t_nbr *temp = data->stack_a;
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
/*
void	quick_sort_2(t_nbr *stack, int size)
{
	t_nbr	*wall;
	int	i;
	int	pivot;

	pivot = size - 1;
	wall = stack;
	i = 0;
	while (i < size)
	{
		if (stack->nbr < pivot)
		{
			if (wall != stack)
					
		}
	}
	quick_sort_2(stack, wall - 1);
	quick_sort_2(stack + wall -1, size - wall + 1);
}*/
