/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubbles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:36:07 by ccottin           #+#    #+#             */
/*   Updated: 2022/05/02 15:37:58 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	count_move(t_nbr *stack, int rank)
{
	int	i;
	int	total;
	t_nbr	*temp;

	i = 0;
	total = 0;
	temp = stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
		total++;
	}
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

t_nbr	*find_small(t_nbr *stack, int small)
{
	t_nbr	*temp;

	temp = stack;
	while (temp->ord != small)
		temp = temp->next;
	return (temp);
}

void	ft_ra(t_data *data, t_nbr *small)
{
	while (data->stack_a != small)
		ra(data, 0);
}

void	ft_rra(t_data *data, t_nbr *small)
{
	while (data->stack_a != small)
		rra(data, 0);
}

int	check_ord(t_data *data)
{
	int	i;
	t_nbr	*temp;

	i = 0;
	if (data->stack_b == NULL)
		return (0);
	temp = data->stack_b;
	while (temp->next != NULL)
	{
		if (temp->ord == temp->next->ord + 1)
			i++;
		temp = temp->next;
	}
	i++;
	temp = data->stack_a;
	while (temp->next != NULL)
	{
		if (temp->ord == temp->next->ord - 1)
			i++;
		temp = temp->next;
	}
	i++;
	if (i == data->total)
		return (1);
	return (0);
}

void	check_last(t_data *data)
{
	t_nbr	*temp;

	temp = data->stack_a;
	while (temp->next != NULL)
		temp = temp->next;
	if (data->stack_a->ord > temp->ord)
		ra(data, 0);
}

void	bubble_sort(t_data *data)
{
	t_nbr	*small;
	int	move;
	int	i;
	
	i = 0;
	while (check_ord(data) != 1 && i < data->total)
	{
		small = find_small(data->stack_a, i);
		move = count_move(data->stack_a, i);
		if (move > 0)
			ft_ra(data, small);
		if (move < 0)
			ft_rra(data, small);
		pb(data);
		if (data->stack_a->ord > data->stack_a->next->ord)
			sa(data, 0);
		check_last(data);
		i++;
	}
	while (data->stack_b != NULL)
		pa(data);
}
