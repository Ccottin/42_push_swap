/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_bin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:00:27 by ccottin           #+#    #+#             */
/*   Updated: 2022/05/05 16:01:17 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*get_int(unsigned int nb)
{
	char	*ret;
	int		i;

	ret = ft_calloc(33);
	if (!ret)
		return (NULL);
	i = 31;
	while (i != -1)
	{
		if ((nb & 1) == 1)
			ret[i] = '1';
		else
			ret[i] = '0';
		nb >>= 1;
		i--;
	}
	return (ret);
}

void	get_bin(t_data *data)
{
	t_nbr	*tmp;
	int		temp;

	tmp = data->stack_a;
	while (tmp != NULL)
	{
		temp = tmp->ord;
		tmp->bin = get_int(temp);
		if (!tmp->bin)
			c_error(data);
		tmp = tmp->next;
	}
}
