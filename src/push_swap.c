/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:19:43 by ccottin           #+#    #+#             */
/*   Updated: 2022/05/02 15:55:28 by ccottin          ###   ########.fr       */
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
//sort3 a modifier pour qu il soit adaptable a d autres bails -> 4 et 5 et 6 vu que 6/2 == 3 a voir sion fait des temp ord? 
void	sort_3(t_data *data)
{
	if (data->stack_a->ord == 0)
	{
		rra(data, 0);
		sa(data, 0);
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
void	check_proceed(t_data *data, int algo, char **av, int ac)
{
	if (check_sorted(data) == 1)
	{
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
		if (algo == 2)
		{
			data->truc.move = ft_strdup(data->temp.move);
			data->truc.nb_move = data->temp.nb_move;
		}
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
/*
void	comp_algo(t_data *data)
{
potentiellement creer un min puis le remplacer des qu on trouve + petit, also = comment faire pour gardertrace de qulle ligne afficher ppeut etre avec un struct algo min et on la remplace des au on a le min ou c good gopush o///	

}*/

void	push_swap(t_data *data, char **av, int ac)
{
	ft_init(data, av, ac);
	if (check_sorted(data) == 1)
		end(data);
	if (data->total == 2)
		sa(data, 0);
	else if (data->total == 3)
		sort_3(data);
//	else if (data->total == 4)
//		sort_4(data);faire bcp de test et comp si un algo peut être en desssous de ce nb de move & si tel est le cas on avise
	else
	{
		bubble_sort(data);
		check_proceed(data, 0, av, ac);	
		radix_sort(data);
		check_proceed(data, 1, av, ac);
		truc(data);
		check_proceed(data, 2, av, ac);
	}
//	comp_algo(data);
	printf("%s", data->temp.move);
/*	t_nbr	*temp;
	temp = data->stack_a;
	while (temp != NULL)
	{
		printf("staka nb = %d ord = %d\n", temp->nb, temp->ord);
		temp = temp->next;
	}*/

}
