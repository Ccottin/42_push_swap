/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:32:46 by ccottin           #+#    #+#             */
/*   Updated: 2022/05/05 15:33:12 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pb(t_data *data)
{
	t_nbr	*temp;

	if (data->stack_a == NULL)
		return ;
	temp = data->stack_a;
	data->stack_a = data->stack_a->next;
	temp->next = NULL;
	ft_add_front(&data->stack_b, temp);
	data->temp.move = stock_move(data, "pb");
	data->temp.nb_move++;
}

void	pa(t_data *data)
{
	t_nbr	*temp;

	if (data->stack_b == NULL)
		return ;
	temp = data->stack_b;
	data->stack_b = data->stack_b->next;
	temp->next = NULL;
	ft_add_front(&data->stack_a, temp);
	data->temp.move = stock_move(data, "pa");
	data->temp.nb_move++;
}

void	sa(t_data *data, int x)
{
	t_nbr	*temp;

	if (data->stack_a->next == NULL)
		return ;
	temp = data->stack_a;
	data->stack_a = data->stack_a->next;
	temp->next = data->stack_a->next;
	data->stack_a->next = temp;
	if (x == 0)
	{
		data->temp.move = stock_move(data, "sa");
		data->temp.nb_move++;
	}
}

void	sb(t_data *data, int x)
{
	t_nbr	*temp;

	if (data->stack_b->next == NULL)
		return ;
	temp = data->stack_b;
	data->stack_b = data->stack_b->next;
	temp->next = data->stack_b->next;
	data->stack_b->next = temp;
	if (x == 0)
	{
		data->temp.move = stock_move(data, "sb");
		data->temp.nb_move++;
	}
}

void	ss(t_data *data)
{
	sa(data, 1);
	sb(data, 1);
	data->temp.move = stock_move(data, "ss");
	data->temp.nb_move++;
}
