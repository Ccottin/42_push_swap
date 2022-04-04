#include "../include/push_swap.h"
#include <stdio.h>


//verifier + coder si le checker accepte les whitespaces ou pas, pour l'instant il les accepte
//check si tout le bail est déjà trié

void	error(int err, t_nbr *stack_a)
{
	write(2, "Error\n", 6);
	ft_lstclear(&stack_a);
	if (err == -1)
		exit(0);
	if (err == -2)
		exit(1);
}

int	check_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (((str[i] < 47 || str[i] > 58) && (str[i] < 9 || str[i] > 13))
			|| str[i] != 45 || str[i] != 43 || str[i] != 32)
			return (-1);
		i++;
	}
	return (0);
}

int	check_nbr(t_nbr *stack_a, long int nb)
{
	t_nbr	*temp;

	if (nb > 2147483647 || nb < -2147483648)
			return (-1);
	temp = stack_a;
	while (temp != NULL)
	{
		if (temp->nb == nb)
			return (-1);
		temp = temp->next;
	}
	return (0);
}

int	check_arg(char **av)
{
	int		i;
	long int	nb;
	t_nbr		*temp;
	t_nbr		*stack_a;

	stack_a = NULL;
	i = 1;
	while (av[i])
	{
	/*	if (check_char(av[i]) == -1)
			return (-1);*/
		nb = ft_atoi(av[i]);
		if (!nb)
			error(-2, stack_a);
		if (check_nbr(stack_a, nb) == -1)
			error(-1, stack_a);
		temp = ft_lstnew(nb);
		if (!temp)
			error(-2, stack_a);
		ft_add_back(&stack_a, temp);
		i++;
	}
	ft_lstclear(&stack_a);
	return (0);
}
