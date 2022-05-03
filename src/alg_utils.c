/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    alg_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:30:40 by ccottin           #+#    #+#             */
/*   Updated: 2022/05/01 19:40:53 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
		return (-1);
	return (1);
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
