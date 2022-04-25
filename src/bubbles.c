#include "../include/push_swap.h"

int	count_move(t_nbr *stack, int rank)
{
	int	i;
	int	total;
	t_nbr	*temp;

	i = 0;
	total = 0;
	temp = stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
		total++;
	}
	temp = stack;
	while (temp->ord != rank)
	{
		printf("temp = %d, rank = %d", temp->ord, rank);
		temp = temp->next;
		i++;
	}
	if (i > total / 2)
		return (i - total - 1);
	return (i);
}

t_nbr	*find_small(t_nbr *stack, int small)
{
	t_nbr	*temp;

	temp = stack;
	while (temp->ord != small)
		temp = temp->next;
	return (temp);
}

void	ft_ra(t_data *data, t_nbr *small)
{
	while (data->stack_a != small)
	{
		if (data->stack_a->ord < data->total / 2)
			pb(data);
		else
			ra(data, 0);
		if (data->stack_a->ord < data->stack_a->next->ord && data->stack_b->ord 
			&& data->stack_b->ord < data->stack_b->next->ord)
			ss(data);
		else if (data->stack_a->ord < data->stack_a->next->ord)
			sa(data, 0);
		else if (data->stack_b->ord && data->stack_b->ord < data->stack_b->next->ord)
			sb(data, 0);
	}
}

void	ft_rra(t_data *data, t_nbr *small)
{
	while (data->stack_a != small)
	{
		if (data->stack_a->ord < data->total / 2)
			pb(data);
		else
			rra(data, 0);
		if (data->stack_b->ord && data->stack_b->ord)
		{
			if (data->stack_a->ord < data->stack_a->next->ord
				&& data->stack_b->ord < data->stack_b->next->ord)
				ss(data);
			else if (data->stack_a->ord < data->stack_a->next->ord)
				sa(data, 0);
			else if (data->stack_b->ord < data->stack_b->next->ord)
				sb(data, 0);
		}
	}
}

void	bubble_sort(t_data *data)
{
	t_nbr	*small;
	int	move;

	small = find_small(data->stack_a, 0);
	move = count_move(data->stack_a, 0);
	if (move > 0)
		ft_ra(data, small);
	if (move < 0)
		ft_rra(data, small);
	pb(data);
	rb(data, 0);
}
