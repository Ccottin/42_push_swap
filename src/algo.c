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

/*	if (data->stack_b && data->stack_b->next && data->stack_a && data->stack_a->next
	&& data->stack_a->ord < data->stack_a->next->ord
	&& data->stack_b->ord > data->stack_b->next->ord)
		ss(data);
	else if (data->stack_b && data->stack_b->next
		&& data->stack_b->ord > data->stack_b->next->ord)
		sb(data, 0);
	else if (data->stack_a->ord < data->stack_a->next->ord
		&& data->stack_a->ord < data->stack_a->next->ord)
		sa(data, 0);*/
		//raouter un trieur de b ici?

t_nbr	*get_pivot(t_data *data, int max, int min)
{
	t_nbr	*temp;
	int	i;

	temp = data->stack_a;
	i = min;
	while (temp->next != NULL && i < max - 1)
	{
		temp = temp->next;
		i++;
	}
	return (temp);
}

void	compare(t_data *data, t_nbr *pivot, int big, int max, int min)
{
//	printf("pivot = %d, data = %d, big = %d\n", pivot->ord, data->stack_a->ord, big);
	if (pivot->ord == big)
		pivot = get_pivot(data, max - 1, min);
//	printf("pivot = %d, data = %d\n", pivot->ord, data->stack_a->ord);
	if (pivot->ord >= data->stack_a->ord)
		pb(data);
	else
		ra(data, 0);
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

int	is_sorted(t_data *data, int min)
{
	t_nbr	*temp;
	int	ret;

	ret = 0;
	temp = data->stack_a;
	while (ret < min)
	{
		temp = temp->next;
		ret++;
	}
	ret = 0;
	while (temp->ord < temp->next->ord)
	{
		temp = temp->next;
		ret++;
	}
	printf("ret = %d ", ret);
	return (ret);
}

void	quick_sort(t_data *data, int min, int max)
{
	t_nbr	*pivot;
	int	big;
	int	i;

	
//	printf("avant r2cu = min = %d max = %d\n", min , max);
	if (min < max && is_sorted(data, min) <= max - 1)
	{
		printf("max = %d\n", max);
		printf("min = %d\n", min);	
		ft_test1(data);
		pivot = get_pivot(data, max, min);
		big = check_biggest(data, max);
//		printf("big = %d\n", big);
		printf("pivot = %d\n", pivot->ord);
		i = 0;
		while (i != max - min)
		{
			compare(data, pivot, big, max, min);
			i++;
		}
		i = 0;
		ft_test1(data);
		while (data->stack_b != NULL)
		{
		/*	if (data->stack_b && data->stack_b->next
			&& data->stack_a && data->stack_a->next
			&& data->stack_a->ord < data->stack_a->next->ord
			&& data->stack_b->ord > data->stack_b->next->ord)
				ss(data);
			else if (data->stack_b && data->stack_b->next
			&& data->stack_b->ord > data->stack_b->next->ord)
				sb(data, 0);*/
	/*		big = 0;
			while (big < ft_lstlen(data->stack_a) - ft_lstlen(data->stack_b))
			{
				rra(data, 0);
				big++;
			}*/
			if (data->stack_a && data->stack_a->next
			&& data->stack_a->ord > data->stack_a->next->ord)
				sa(data, 0);
			pa(data);
			i++;

		}
//		printf("i = %d\n", i);
		if (check_sorted(data) == 1)
			return;
//		printf("avant r2cu = max = %d, ", max);
//		printf("min = %d\n", min);
		big = 0;
	/*	while (big < i)
		{
			ra(data, 0);
			big++;
		printf("i = %d, big = %d\n", i, big);
		}*/
		quick_sort(data, min, i - 1);
		quick_sort(data, i + 1, data->total);
	}
}
