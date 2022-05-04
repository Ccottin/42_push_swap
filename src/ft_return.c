/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:19:46 by ccottin           #+#    #+#             */
/*   Updated: 2022/04/28 17:01:56 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	freeable(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_bean(t_nbr *stack)
{
	t_nbr	*temp;
	
	temp = stack;
	while (temp != NULL)
	{
		if (temp->bin != NULL)
			free(temp->bin);
		temp = temp->next;
	}
}
void	free_all(t_data *data)
{
	free_bean(data->stack_a);
	free_bean(data->stack_b);
	ft_lstclear(&(data->stack_a));
	ft_lstclear(&(data->stack_b));
	if (data->bubble.move != NULL)
		free(data->bubble.move);
	if (data->truc.move != NULL)
		free(data->truc.move);
	if (data->radix.move != NULL)
		free(data->radix.move);
	if (data->temp.move != NULL)
		free(data->temp.move);
	if (data->small.move != NULL)
		free(data->small.move);
	if (data->tab != NULL)
		freeable(data->tab);
}

void	c_error(t_data *data)
{
	free_all(data);
	exit(1);
}

void	end(t_data *data)
{
	free_all(data);
	exit(0);
}
