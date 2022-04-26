/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:35:34 by ccottin           #+#    #+#             */
/*   Updated: 2022/04/26 17:54:03 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*get_int(unsigned int nb)
{
	char	*ret;
	int	i;

	ret = ft_calloc(33);
	if (!ret)
		return (NULL);
	i = 31;
	/*if (nb < 0)
		ret[0] = '1';
	else
		ret[0] = '0';*/
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
	int	temp;
	t_nbr	*tmp;

	tmp = data->stack_a;
	while (tmp != NULL)
	{
		temp = tmp->nb;
		tmp->bin = get_int(temp);
		if (!tmp->bin)
			c_error(data);
		tmp = tmp->next;
	}
}

void	sort(t_data *data, int base, char c)
{
	if (data->stack_a->bin[base] == c)
		pb(data);
	else
		ra(data, 0);
}

void	ft_test(t_data *data)
{
	t_nbr *temp;

	temp = data->stack_a;
	while (temp != NULL)
	{	
		printf("A nb = %s ord = %d\n", temp->bin, temp->ord);
		temp = temp->next;
	}
	temp = data->stack_b;
	while (temp != NULL)
	{
		printf("B nb = %s ord = %d\n", temp->bin, temp->ord);
		temp = temp->next;
	}
}

void	radix_sort(t_data *data)
{
	int	i;
	int	j;

	get_bin(data);
	i = 31;
	while (i != 0)
	{
		j = 0;
		while (j < data->total)
		{
			sort(data, i, '0');
			j++;
		}
		while (data->stack_b != NULL)
			pa(data);
		i--;
	}
	j = 0;
	while (j < data->total)
	{
		sort(data, 0, '1');
		j++;
	}
	while (data->stack_b != NULL)
			pa(data);


}
