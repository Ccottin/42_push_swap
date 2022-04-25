/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:23:54 by ccottin           #+#    #+#             */
/*   Updated: 2022/04/13 18:21:26 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
		if ((str[i] < 48 || str[i] > 57) && str[i] != 45
			&& str[i] != 43 && str[i] != 32)
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

int	fill_stack(char **tab, t_nbr **stack_a, int m)
{
	int	i;
	t_nbr	*temp;
	long int	nb;

	i = 0;
	while (tab[i])
	{
		if (i == 0)
			i += m;
		if (check_char(tab[i]) == -1)
			return (-1);
		nb = ft_atoi(tab[i]);
		if (check_nbr(*stack_a, nb) == -1)
			return (-1);
		temp = ft_lstnew(nb);
		if (!temp)
			return (-2);
		ft_add_back(stack_a, temp);
		i++;
	}
	return (0);
}

int	check_arg(char **av, int m)
{
	int	i;
	t_nbr		*stack_a;

	stack_a = NULL;
	i = 0;
	while (av[i])
		i++;
	if (i < 2)
	{
		freeable(av);
		exit(0);
	}
	i = fill_stack(av, &stack_a, m);
	if (i != 0 && m == 0)
		freeable(av);
	if (i != 0)
		error(i, stack_a);
	ft_lstclear(&stack_a);
	return (0);
}
