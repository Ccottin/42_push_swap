
#include "../include/push_swap.h"

void	get_tmp_ord(t_nbr *stack, t_nbr **comp)
{
	t_nbr	*tmp;
	int	sup;

	tmp = stack;
	sup = 0;
	while (tmp != NULL)
	{
		if (tmp->nb < (*comp)->nb)
			sup++;
		tmp = tmp->next;
	}
	(*comp)->tp_ord = sup;
}

void	get_temp_ord(t_nbr *stack)
{
	t_nbr	*temp;
	
	temp = stack;
	while (temp != NULL)
	{
		get_tmp_ord(stack, &temp);
		temp = temp->next;
	}
}

void	sort_3(t_data *data)
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

void	sort_4(t_data *data)
{
	int	small;

	get_temp_ord(data->stack_a);
	small = find_smallest(data->stack_a);
	if (count_move(data->stack_a, small) < 0)
	{
		while (data->stack_a->ord != small)
			rra(data, 0);
	}
	else
	{
		while (data->stack_a->ord != small)
			ra(data, 0);
	}
	pb(data);
	sort_3(data);
	pa(data);
}
