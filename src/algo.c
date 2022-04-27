/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:55:14 by ccottin           #+#    #+#             */
/*   Updated: 2022/04/27 19:27:10 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//full optimisable

void	compare(t_data *data, t_nbr *pivot, int big)
{
	if (pivot->ord == big)
		return ;
	printf("pivot = %d, data = %d\n", pivot->ord, data->stack_a->ord);
	if (pivot->ord >= data->stack_a->ord)
			pb(data);
	else
		ra(data, 0);
		//raouter un trieur de b ici?
}

t_nbr	*get_pivot(t_data *data, int max)
{
	t_nbr	*temp;
	int	i;

	temp = data->stack_a;
	i = 0;
	while (temp->next != NULL && i < max - 1)
	{
		temp = temp->next;
		i++;
	}
	return (temp);
}

int	get_pivot_place(t_data *data, t_nbr *pivot)
{
	int	i;
	t_nbr	*temp;

	temp = data->stack_a;
	while (temp != pivot)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void	ft_test1(t_data *data)
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

int	check_biggest(t_data *data, int max)
{
	t_nbr	*temp;
	int	ret;
	int	i;

	ret = 0;
	temp = data->stack_a;
	i = 0;
	while (i < max)
	{
		if (temp->ord > ret)
			ret = temp->ord;
		temp = temp->next;
		i++;
	}
	return (ret);
}

void	quick_sort(t_data *data, int min, int max)
{
	t_nbr	*pivot;
	int	big;
	int	i;
	
	if (min < max)
	{
		printf("max = %d, ", max);
		printf("min = %d\n", min);
		pivot = get_pivot(data, max);
		big = check_biggest(data, max);
		printf("big = %d\n", big);
		printf("pivot = %d\n", pivot->ord);
		i = 0;
		while (i != max - min)
		{
			compare(data, pivot, big);
			i++;
		}
		i = 0;
		ft_test1(data);
		while (data->stack_b != NULL)
		{
			pa(data);
			i++;
		}
		printf("i = %d\n", i);
		ft_test1(data);
		if (check_sorted(data) == 1)
			return;
		printf("avant r2cu = max = %d, ", max);
		printf("min = %d\n", min);
		quick_sort(data, min, i - 1);
		quick_sort(data, max, data->total - max);
	}
}
