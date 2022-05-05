/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:23:20 by ccottin           #+#    #+#             */
/*   Updated: 2022/05/05 16:25:59 by ccottin          ###   ########.fr       */
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

int	get_s_last(t_nbr *stack)
{
	t_nbr	*temp;

	temp = stack;
	while (temp->next->next != NULL)
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

int	sorted(t_nbr *stack)
{
	int		i;
	int		len;
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

void	put_biggest(t_data *data)
{
	if (data->stack_a->next->ord > data->stack_a->ord - 2)
		check_ss(data);
	if (get_last(data->stack_a) == data->total - 1)
		rra(data, 0);
	if (get_s_last(data->stack_a) == data->total - 1)
	{
		rra(data, 0);
		rra(data, 0);
		check_ss(data);
	}
	if (data->stack_b->ord == data->total - 1)
		pa(data);
}
