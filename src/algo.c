/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:55:14 by ccottin           #+#    #+#             */
/*   Updated: 2022/04/05 13:14:12 by ccottin          ###   ########.fr       */
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
	while (i < data->total)
	{
		printf("comp = %d pivot = %d i =%d \n", data->stack_a->nb, pivot->nb, i);
		if (mark->ord < pivot->ord)
		{
			printf("pivot = %d, data = %d\n", pivot->nb, data->stack_a->nb);
			pb(data);
		}
		else
			mark = mark->next;
		i++;
	}
}
