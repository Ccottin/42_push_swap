/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:23:41 by ccottin           #+#    #+#             */
/*   Updated: 2022/05/02 15:47:55 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	get_ord(t_data *data, t_nbr **comp)
{
	t_nbr	*tmp;
	int	sup;

	tmp = data->stack_a;
	sup = 0;
	while (tmp != NULL)
	{
		if (tmp->nb < (*comp)->nb)
			sup++;
		tmp = tmp->next;
	}
	(*comp)->ord = sup;
	(*comp)->tp_ord = 0;
	(*comp)->bin = NULL;
}

void	ord_stacka(t_data *data)
{
	int	total;
	t_nbr	*tmp;

	tmp = data->stack_a;
	total = 0;
	while (tmp != NULL)
	{
		get_ord(data, &tmp);
		tmp = tmp->next;
		total++;
	}
	data->total = total;
}

void	init_stack_a(t_data *data, char **av, int ac)
{
	t_nbr	*temp;
	int	i;
	int	nb;

	i = 1;
	if (ac == 2)
		i = 0;
	while (av[i])
	{
		nb = ft_atoi(av[i]);
		temp = ft_lstnew(nb);
		if (!temp)
			c_error(data);
		ft_add_back(&(data->stack_a), temp);
		i++;
	}
	ord_stacka(data);
}

void	ft_init(t_data *data, char **av, int ac)
{
	t_nbr	*stack_a;
	t_nbr	*stack_b;

	if (ac == 2)
		av = data->tab;
	stack_a = NULL;
	data->stack_a = stack_a;
	init_stack_a(data, av, ac);
	stack_b = NULL;
	data->stack_b = stack_b;
	data->temp.nb_move = 0;
	data->bubble.nb_move = 0;
	data->radix.nb_move = 0;
	data->truc.nb_move = 0;
	data->truc.move = NULL;
	data->bubble.move = NULL;
	data->radix.move = NULL;
	data->temp.move = NULL;
}
