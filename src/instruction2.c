#include "../include/push_swap.h"

void	ra(t_data *data, int x)
{
	t_nbr	*temp;
	t_nbr	*run;

	if (data->stack_a == NULL || data->stack_a->next == NULL)
		return;
	temp = data->stack_a;
	data->stack_a = data->stack_a->next;
	run = data->stack_a;
	while (run->next != NULL)
		run = run->next;
	run->next = temp;
	temp->next = NULL;
	if (x == 0)
	{
		data->temp.move = stock_move(data, "ra");
		data->temp.nb_move++;
	}
}

void	rb(t_data *data, int x)
{
	t_nbr	*temp;
	t_nbr	*run;

	if (data->stack_b == NULL || data->stack_b->next == NULL)
		return;
	temp = data->stack_b;
	data->stack_b = data->stack_b->next;
	run = data->stack_b;
	while (run->next != NULL)
		run = run->next;
	run->next = temp;
	temp->next = NULL;
	if (x == 0)
	{
		data->temp.move = stock_move(data, "rb");
		data->temp.nb_move++;
	}
}

void	rr(t_data *data)
{
	ra(data, 1);
	rb(data, 1);
	data->temp.move = stock_move(data, "rr");
	data->temp.nb_move++;

}
