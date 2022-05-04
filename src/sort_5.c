
#include "../include/push_swap.h"

void	sort_5_bis(t_data *data, int mark)
{
	int	small;
	
	small = find_smallest(data->stack_a);
	if (count_move(data->stack_a, small) < 0)
	{
		while (data->stack_a->ord != small)
			rra(data, 0);
		if (mark == 1 && data->stack_a->ord == small + 1)
			pb(data);
	}
	else
	{
		while (data->stack_a->ord != small)
			ra(data, 0);
		if (mark == 1 && data->stack_a->ord == small + 1)
			pb(data);
	}	
}

void	norm_35(t_data *data)
{
	if (data->stack_b->ord < data->stack_b->next->ord)
		ss(data);
	else	
		sa(data, 0);
}

void	sort_35(t_data *data)
{
	get_temp_ord(data->stack_a);
	if (check_sorted(data->stack_a) == 1)
		return ;
	if (data->stack_a->tp_ord == 0)
	{
		rra(data, 0);
		norm_35(data);
	}
	else if (data->stack_a->tp_ord == 2 && data->stack_a->next->tp_ord == 1)
	{
		ra(data, 0);
		norm_35(data);
	}
	else if (data->stack_a->tp_ord == 2 && data->stack_a->next->tp_ord == 0)
		ra(data, 0);
	else if (data->stack_a->tp_ord == 1 && data->stack_a->next->tp_ord == 0)
		norm_35(data);
	else if (data->stack_a->tp_ord == 1 && data->stack_a->next->tp_ord == 2)
		rra(data, 0);
}

void	sort_5(t_data *data)
{
	get_temp_ord(data->stack_a);
	sort_5_bis(data, 1);
	pb(data);
	if (ft_lstlen(data->stack_b) == 1)
	{
		sort_5_bis(data, 0);
		pb(data);
	}
	sort_35(data);
	if (data->stack_b->tp_ord < data->stack_b->next->tp_ord)
		sb(data, 0);
	pa(data);
	pa(data);
}
