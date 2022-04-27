/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:35:34 by ccottin           #+#    #+#             */
/*   Updated: 2022/04/27 21:18:35 by ccottin          ###   ########.fr       */
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
/*binaire du nombre
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
}*/

void	get_bin(t_data *data)
{
	int	temp;
	t_nbr	*tmp;

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

int	thers_one(t_nbr *stack, int base)
{
	t_nbr	*temp;

	temp = stack;
	while (temp != NULL)
	{
		if (temp->bin[base] == '1')
			return (1);
		temp = temp->next;
	}
	return (0);
}
void	push_to_b(t_data *data, int base)
{
	int	j;
	int	total;

	j = 0;
	total = ft_lstlen(data->stack_a);
	while (j < total && thers_one(data->stack_a, base) == 1)
	{
		if (ft_lstlen(data->stack_a) == 2)
		{
			if (data->stack_a->ord < data->stack_a->next->ord)
				sa(data, 0);
		}
		else if (data->stack_a->bin[base] == '0')
			pb(data);
		else
			ra(data, 0);
		j++;
	}
}

int	check_pre_sorted(t_data *data)
{
	int	i;
	int	start;
	t_nbr	*temp;

	temp = data->stack_a;
	start = 0;
	while (temp->ord != 0)
	{
		temp = temp->next;
		start++;
	}
	i = 0;
	while (i != data->total)
	{
		if (temp == NULL)
			temp = data->stack_a;
		if (i == temp->ord)
		{
			temp = temp->next;
			i++;
		}
		else
			return (0);
	}
	return (start);
}

void	pre_sort(t_data *data, int start)
{
	if (start > data->total / 2)
	{
		while (start != data->total)
		{
			rra(data, 0);
			start++;
		}
	}
	else
	{
		while (start != 0)
		{
			ra(data, 0);
			start--;
		}
	}
}

void	radix_sort(t_data *data)
{
	int	base;
	int	total;

	get_bin(data);
	base = 31;
	while (base != 0)
	{
		push_to_b(data, base);
		total = ft_lstlen(data->stack_b);
		while (0 != total)
		{
		//	printf("char = %c, i = %d\n", data->stack_b->bin[base - 1], total);
		//	if (data->stack_b->bin[base - 1] == '1')
				pa(data);
			total--;
		}
		ft_test(data);
		base--;
		total = check_pre_sorted(data);
		if (total != 0)
			pre_sort(data, total);
		if (check_sorted(data) == 1)
			return;
	}
	base = 0;
	total = ft_lstlen(data->stack_a);
	while (base < total)
	{
		if (data->stack_a->bin[0] == '1')
			pb(data);
		else
			ra(data, 0);
		base++;
	}
	while (data->stack_b != NULL)
		pa(data);
}
