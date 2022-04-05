#include "../include/push_swap.h"

int	check_sorted(t_data *data)
{
	t_nbr	*temp;
	int	i;

	temp = data->stack_a;
	i = 0;
	while (temp != NULL && i == temp->ord)
	{
		temp = temp->next;
		i++;
	}
	if (i == data->total)
		return (1);
	return (0);
}

void	push_swap(t_data *data, char **av)
{
	ft_init(data, av);
	t_nbr	*temp;
	temp = data->stack_a;
	while (temp != NULL)
	{
		printf("staka nb = %d ord = %d\n", temp->nb, temp->ord);
		temp = temp->next;
	}

	if (check_sorted(data) == 1)
		end(data);
	quick_sort(data);
//	t_nbr	*temp;
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
