#include "../include/push_swap.h"

t_nbr	*find_pivot(t_data *data)
{
	t_nbr	*pivot;

	pivot = data->stack_a;
	while (pivot->next != NULL)
		pivot = pivot->next;
	return (pivot);
}

void	quick_sort(t_data *data)
{
	t_nbr	*pivot;
	t_nbr	*comp;
	int	i;

	comp = data->stack_a;
	pivot = find_pivot(data);
 	i = 0;
	printf("%d\n", pivot->nb);
	while (i < data->total)
	{
		if (comp->nb < pivot->nb)
		{
			pb(data);
		}
		printf("%d\n", comp->nb);
		comp = comp->next;
		printf("%d\n", comp->nb);
		i++;
	}
}
