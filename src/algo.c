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

t_nbr	*find_pivot(t_data *data)
{
	t_nbr	*pivot;

	pivot = data->stack_a;
	while (pivot->next != NULL)
		pivot = pivot->next;
	return (pivot);
}

void	quick_sort(t_data *data)
{
	t_nbr	*pivot;
	t_nbr	*mark;
	int	i;

	mark = data->stack_a;
	pivot = find_pivot(data);
 	i = 0;
	while (i < data->total && data->stack_a != NULL)
	{
		printf("comp = %d pivot = %d i =%d \n", data->stack_a->nb, pivot->nb, i);
		if (data->stack_a->ord == pivot->ord)
			pb(data);
		else if (data->stack_a->ord < pivot->ord)
		{
			printf("pivot = %d, data = %d\n", pivot->nb, data->stack_a->nb);
			pb(data);
		}
		printf("appel %d, stack a = %d, \n", i, data->stack_a->nb);
		else
			data->stack_a = data->stack_a->next;
		i++;
		if (data->stack_a != NULL)
		printf("appel %d, stack a = %d, \n", i, data->stack_a->nb);
		if (data->stack_b != NULL)
			printf("stack b = %d\n\n", data->stack_b->nb);
	}
	data->stack_a = mark;
	printf("%p\n", &data->stack_a);
}
