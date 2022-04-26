/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:35:34 by ccottin           #+#    #+#             */
/*   Updated: 2022/04/26 20:07:38 by ccottin          ###   ########.fr       */
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

void	ft_test(t_data *data)
{
	t_nbr *temp;

	printf("\n");
	printf("\n");
	temp = data->stack_a;
	while (temp != NULL)
	{	
		printf("A nb = %s ord = %d\n", temp->bin, temp->ord);
		temp = temp->next;
	}
	printf("\n");
	temp = data->stack_b;
	while (temp != NULL)
	{
		printf("B nb = %s ord = %d\n", temp->bin, temp->ord);
		temp = temp->next;
	}
	printf("\n");
	printf("\n");
}

void	re_sort(t_data *data, int base, char c)
{
	int	j;
	int	total;

	total = ft_lstlen(data->stack_b);
	j = 0;
	while (j < total && data->stack_b != NULL)
	{
		if (data->stack_b->bin[base] == c)
			pa(data);
		else
			rb(data, 0);
		j++;
	}
}

void	sort2(t_data *data, int base, char c)
{
	int	j;
	int	total;

	total = ft_lstlen(data->stack_a);
	j = 0;
	while (j < total)
	{
		if (data->stack_a->bin[base] == c && data->stack_a->bin[base - 1] != c)
			pb(data);
		else
			ra(data, 0);
		j++;
	}
}

void	sort(t_data *data, int base, char c)
{
	int	j;
	int	total;

	total = ft_lstlen(data->stack_a);
	j = 0;
	while (j < total)
	{
		if (data->stack_a->bin[base] == c && data->stack_a->bin[base - 1] == c)
			pb(data);
		else
			ra(data, 0);
		j++;
	}
}

void	last_sort(t_data *data, int base, char c)
{
	int	j;
	int	total;

	total = ft_lstlen(data->stack_a);
	j = 0;
	while (j < total)
	{
		if (data->stack_a->bin[base] == c)
			pb(data);
		else
			ra(data, 0);
		j++;
	}
}

void	radix_sort(t_data *data)
{
	int	i;

	get_bin(data);
	i = 31;
	while (i != 1)
	{
		sort(data, i, '0');
		sort2(data, i, '1');
		sort2(data, i, '0');
		ft_test(data);
		i = i - 2;
		while (data->stack_b != NULL)
			pa(data);
	}
	last_sort(data, 1, '0');
	while (data->stack_b != NULL)
			pa(data);
	last_sort(data, 0, '1');
	while (data->stack_b != NULL)
			pa(data);
	ft_test(data);

}
/*
void	radix_sort(t_data *data)
{
	int	i;

	get_bin(data);
	i = 31;
	while (i != 1)
	{
		sort(data, i, '0');
		sort2(data, i, '1');
		sort(data, i - 1, '0');
		re_sort(data, i - 1, '1');
		re_sort(data, i - 1, '0');
		i = i - 2;
		while (data->stack_b != NULL)
			pa(data);
	}
	sort(data, 1, '0');
	while (data->stack_b != NULL)
			pa(data);
	sort(data, 0, '1');
	while (data->stack_b != NULL)
			pa(data);
	ft_test(data);

}*/
