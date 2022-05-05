/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:23:54 by ccottin           #+#    #+#             */
/*   Updated: 2022/05/05 18:52:56 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < 48 || str[i] > 57) && str[i] != 45
			&& str[i] != 43 && str[i] != 32)
			return (-1);
		if ((str[i] >= 48 && str[i] <= 57) && (str[i + 1] == 45
				|| str[i + 1] == 43))
			return (-1);
		i++;
	}
	i = 0;
	while (str[i] == 45 || str[i] == 43)
			i++;
	if (ft_strlen(str) == i)
		return (-1);
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
	t_nbr		*temp;
	int			i;
	long int	nb;

	i = 0;
	while (tab[i])
	{	
		if (i == 0)
			i += m;
		if (*stack_a != NULL && ft_strncmp(tab[i], "") == 0)
			error(-1, *stack_a);
		if (ft_strncmp(tab[i], "") == 0)
			exit(0);
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

void	case_i_1(char **av, t_nbr *stack_a)
{
	if (!av[0])
	{
		freeable(av);
		exit(0);
	}
	if (check_char(av[0]) == -1)
	{
		freeable(av);
		error(-1, stack_a);
	}
	if (check_nbr(stack_a, ft_atoi(av[0])) == -1)
	{
		freeable(av);
		error(-1, stack_a);
	}
	freeable(av);
	exit(0);
}

int	check_arg(char **av, int m)
{
	int		i;
	t_nbr	*stack_a;

	stack_a = NULL;
	i = 0;
	while (av[i])
		i++;
	if (i < 2)
		case_i_1(av, stack_a);
	i = fill_stack(av, &stack_a, m);
	if (i != 0)
	{
		if (m == 0)
			freeable(av);
		error(i, stack_a);
	}
	ft_lstclear(&stack_a);
	return (0);
}
