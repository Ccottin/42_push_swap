/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:19:43 by ccottin           #+#    #+#             */
/*   Updated: 2022/05/05 18:23:19 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	proceed(t_data *data, char **av, int ac, int algo)
{	
	if (algo == 2 && ultimate_check_sorted(data) == 1 && data->stack_b == NULL)
	{
		data->truc.move = ft_strdup(data->temp.move);
		data->truc.nb_move = data->temp.nb_move;
	}
	free(data->temp.move);
	data->temp.move = NULL;
	data->temp.nb_move = 0;
	ft_lstclear(&(data->stack_a));
	ft_lstclear(&(data->stack_b));
	if (ac == 2)
		init_stack_a(data, data->tab, ac);
	else
		init_stack_a(data, av, ac);
}

void	check_proceed(t_data *data, int algo, char **av, int ac)
{
	if (ultimate_check_sorted(data) == 1 && data->stack_b == NULL)
	{
		if (algo == 4)
		{
			data->small.move = ft_strdup(data->temp.move);
			data->small.nb_move = data->temp.nb_move;
		}
		if (algo == 0)
		{
			data->bubble.move = ft_strdup(data->temp.move);
			data->bubble.nb_move = data->temp.nb_move;
		}
		if (algo == 1)
		{
			data->radix.move = ft_strdup(data->temp.move);
			data->radix.nb_move = data->temp.nb_move;
			free_bean(data->stack_a);
			free_bean(data->stack_b);
		}	
	}
	proceed(data, av, ac, algo);
}

t_algo	*comp_algo(t_data *data)
{
	t_algo	*min;

	min = NULL;
	if (data->small.nb_move != 0)
		min = &(data->small);
	if (data->bubble.nb_move != 0 && (min == NULL
			|| min->nb_move > data->bubble.nb_move))
		min = &(data->bubble);
	if (data->radix.nb_move != 0 && (min == NULL
			|| min->nb_move > data->radix.nb_move))
		min = &(data->radix);
	if (data->truc.nb_move != 0 && (min == NULL
			|| min->nb_move > data->truc.nb_move))
		min = &(data->truc);
	return (min);
}

void	algo_bigger(t_data *data, char **av, int ac)
{
	if (data->total < 150)
		bubble_sort(data);
	check_proceed(data, 0, av, ac);
	if (data->total > 70)
		radix_sort(data);
	check_proceed(data, 1, av, ac);
	if (data->total > 20 && data->total < 350)
		truc(data);
	check_proceed(data, 2, av, ac);
}

void	push_swap(t_data *data, char **av, int ac)
{
	t_algo	*res;

	ft_init(data, av, ac);
	if (ultimate_check_sorted(data) == 1)
		end(data);
	if (data->total == 2)
		sa(data, 0);
	else if (data->total == 3)
		sort_3(data);
	else if (data->total == 4)
		sort_4(data);
	else if (data->total == 5)
		sort_5(data);
	else if (data->total == 6)
		sort_6(data);
	check_proceed(data, 4, av, ac);
	if (data->total >= 6)
		algo_bigger(data, av, ac);
	res = comp_algo(data);
	write(1, res->move, ft_strlen(res->move));
}
