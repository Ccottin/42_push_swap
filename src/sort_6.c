
#include "../include/push_swap.h"

void	sort_3_a(t_data *data)
{
	get_temp_ord(data->stack_a);
	if (check_sorted(data->stack_a) == 1)
		return ;
	if (data->stack_a->tp_ord == 0)
	{
		rra(data, 0);
		sa(data, 0);
	}
	else if (data->stack_a->tp_ord == 2 && data->stack_a->next->tp_ord == 1)
	{
		ra(data, 0);
		sa(data, 0);
	}
	else if (data->stack_a->tp_ord == 2 && data->stack_a->next->tp_ord == 0)
		ra(data, 0);
	else if (data->stack_a->tp_ord == 1 && data->stack_a->next->tp_ord == 0)
		sa(data, 0);
	else if (data->stack_a->tp_ord == 1 && data->stack_a->next->tp_ord == 2)
		rra(data, 0);
}

void	sort_3_b(t_data *data)
{
	get_temp_ord(data->stack_b);
	if (check_sorted_2(data->stack_b) == 1)
		return ;
	if (data->stack_b->tp_ord == 2)
	{
		rrb(data, 0);
		sb(data, 0);
	}
	else if (data->stack_a->tp_ord == 0 && data->stack_a->next->tp_ord == 1)
	{
		rb(data, 0);
		sb(data, 0);
	}
	else if (data->stack_a->tp_ord == 0 && data->stack_a->next->tp_ord == 2)
	{
		rrb(data, 0);
		rrb(data, 0);
	}
	else if (data->stack_a->tp_ord == 1 && data->stack_a->next->tp_ord == 2)
		sb(data, 0);
	else if (data->stack_a->tp_ord == 1 && data->stack_a->next->tp_ord == 0)
		rrb(data, 0);
}

void	feed_b(t_data *data)
{
	int	small;

	small = find_smallest(data->stack_a);
	if (count_move(data->stack_a, small) < 0)
	{
		while (data->stack_a->ord != small)
		{
			if (data->stack_a->ord == small + 1
			|| data->stack_a->ord == small + 2)
				pb(data);
			rra(data, 0);
		}
		pb(data);
	}
	else
	{
		while (data->stack_a->ord != small)
		{
			if (data->stack_a->ord == small + 1
			|| data->stack_a->ord == small + 2)
				pb(data);
			ra(data, 0);
		}
		pb(data);
	}
}

void	fill_b(t_data *data, int len)
{
	int	small;

	small = find_smallest(data->stack_a);
	if (count_move(data->stack_a, small) < 0)
	{
		while (data->stack_a->ord != small)
		{
			if (len == 1 && data->stack_a->ord == small + 1)
				pb(data);
			rra(data, 0);
		}
		pb(data);
	}
	else if (count_move(data->stack_a, small) >= 0)
	{
		while (data->stack_a->ord != small)
		{
			if (len == 1 && data->stack_a->ord == small + 1)
				pb(data);
			ra(data, 0);
		}
		pb(data);
	}
}

void	sort_6(t_data *data)
{
	feed_b(data);
	while (ft_lstlen(data->stack_b) < 3)
		fill_b(data, ft_lstlen(data->stack_b));
	sort_3_a(data);
	sort_3_b(data);
	pa(data);
	pa(data);
	pa(data);
}
