#include "../include/push_swap.h"

void	free_all(t_data *data)
{
	ft_lstclear(&(data->stack_a));
	ft_lstclear(&(data->stack_b));
	if (data->temp.move != NULL)
		free(data->temp.move);
}

void	c_error(t_data *data)
{
	free_all(data);
	exit(1);
}

void	end(t_data *data)
{
	free_all(data);
	exit(0);
}
