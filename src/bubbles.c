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
		temp = temp->next;
		i++;
	}
	if (i > total / 2)
		return (i - total - 1);
	return (i);
}

t_nbr	*find_small(t_nbr *stack)
{
	t_nbr	*small;
	t_nbr	*temp;

	temp = stack;
	small = stack;
	while (temp != NULL)
	{
		if (small->ord > temp->ord)
			small = temp;
		temp = temp->next;
	}
	return (small);
}

int	get_last(t_nbr *stack)
{
	t_nbr	*temp;

	temp = stack;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp->ord);
}

void	check_ss(t_data *data)
{
	if (data->stack_b && data->stack_b->next && data->stack_a && data->stack_a->next
	&& data->stack_a->ord > data->stack_a->next->ord
	&& data->stack_b->ord < data->stack_b->next->ord)
		ss(data);
	else if (data->stack_b && data->stack_b->next
		&& data->stack_b->ord < data->stack_b->next->ord)
		sb(data, 0);
	else if (data->stack_a->ord > data->stack_a->next->ord)
		sa(data, 0);
}

void	ft_ra(t_data *data, t_nbr *small)
{
	int	last_b;

	last_b = -1;
	if (data->stack_b && data->stack_b->next)
		last_b = get_last(data->stack_b);
	while (data->stack_a != small)
	{
		if (data->stack_b && data->stack_b->next)
			last_b = get_last(data->stack_b);
		if (data->stack_a->ord <= small->ord + 5)
			pb(data);
		if (last_b != -1 && data->stack_a && data->stack_a->next
		&& data->stack_b->ord < last_b)
			rr(data);
		else
			ra(data, 0);
		check_ss(data);
	}
}

void	ft_rra(t_data *data, t_nbr *small)
{	
	int	last_b;

	last_b = -1;
	if (data->stack_b && data->stack_b->next)
		last_b = get_last(data->stack_b);
	while (data->stack_a != small)
	{
		if (data->stack_b && data->stack_b->next)
			last_b = get_last(data->stack_b);
		if (data->stack_a->ord <= small->ord + 2)
			pb(data);
		if (last_b != -1 && data->stack_a && data->stack_a->next
		&& data->stack_b->ord > last_b)
			rrr(data);
		else
			rra(data, 0);
		check_ss(data);
	}

	while (data->stack_a != small)
		rra(data, 0);
}

int	check_ord(t_data *data)
{
	int	i;
	t_nbr	*temp;

	i = 0;
	if (data->stack_b == NULL)
		return (0);
	temp = data->stack_b;
	while (temp->next != NULL)
	{
		if (temp->ord == temp->next->ord + 1)
			i++;
		temp = temp->next;
	}
	i++;
	temp = data->stack_a;
	while (temp->next != NULL)
	{
		if (temp->ord == temp->next->ord - 1)
			i++;
		temp = temp->next;
	}
	i++;
	if (i == data->total)
		return (1);
	return (0);
}

void	check_last(t_data *data)
{
	t_nbr	*temp;

	temp = data->stack_a;
	while (temp->next != NULL)
		temp = temp->next;
	if (data->stack_a->ord > temp->ord)
		ra(data, 0);
}

void	ft_test2(t_data *data)
{
	t_nbr	*temp;
	
	temp = data->stack_a;
	while (temp != NULL)
		{
			printf("staka nb = %d ord = %d\n", temp->nb, temp->ord);
			temp = temp->next;
		}
	temp = data->stack_b;
	while (temp != NULL)
		{
			printf("stakb nb = %d ord = %d\n", temp->nb, temp->ord);
			temp = temp->next;
		}
}

void	ft_pa(t_data *data)
{
	int	move;
	int	i;

	i = 0;
	move = count_move(data->stack_a, data->total - 1 - i) + 1;
	if (move > 0)

	printf("mov = %d\n", move);
}

void	bubble_sort(t_data *data)
{
	t_nbr	*small;
	int	move;
	
	small = find_small(data->stack_a);
	while (check_ord(data) != 1 && ft_lstlen(data->stack_b) < data->total / 2)
	{
		small = find_small(data->stack_a);
		move = count_move(data->stack_a, small->ord);
		printf("small = %d\n", small->ord);
		if (move > 0)
			ft_ra(data, small);
		if (move < 0)
			ft_rra(data, small);
		pb(data);
		ft_ss(data);
		ft_test2(data);
		if (data->stack_a->ord > data->stack_a->next->ord)
			sa(data, 0);
		check_last(data);
	}
//	while (data->stack_b != NULL)
	ft_pa(data);
}
