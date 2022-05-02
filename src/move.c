/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:23:23 by ccottin           #+#    #+#             */
/*   Updated: 2022/05/02 14:33:55 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*stock_move(t_data *data, char *move)
{
	int	i;
	int	j;
	char	*ret;

	ret = ft_calloc(ft_strlen(data->temp.move) + ft_strlen(move) + 2);
	if (!ret)
		return (NULL);
	i = 0;
	if (data->temp.move != NULL)
	{
		while (data->temp.move[i])
		{
			ret[i] = data->temp.move[i];
			i++;
		}
	}
	j = 0;
	while (move[j])
	{
		ret[i] = move[j];
		j++;
		i++;
	}
	ret[i] = '\n';
	if (data->temp.move != NULL)
		free(data->temp.move);
	return (ret);
}
