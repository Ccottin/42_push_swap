#include "../include/push_swap.h"
 
// peut-on passer en argument une looongue chaine de caractère avecque des int? entre guillemets

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 3)
		return (0);
	check_arg(av);
	push_swap(&data, av);
	free_all(&data);
	return (0);
}
