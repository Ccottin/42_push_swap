/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:19:46 by ccottin           #+#    #+#             */
/*   Updated: 2022/04/13 21:09:01 by ccottin          ###   ########.fr       */
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

void	free_all(t_data *data)
{
	ft_lstclear(&(data->stack_a));
	ft_lstclear(&(data->stack_b));
	if (data->temp.move != NULL)
		free(data->temp.move);
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
