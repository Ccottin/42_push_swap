/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:23:31 by ccottin           #+#    #+#             */
/*   Updated: 2022/04/05 11:23:33 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_data	data;
	char	**tab;

	if (ac == 2)
	{
		tab = ft_split(av[1], ' ');
		if (!tab)
			exit(1);
		check_arg(tab, 0);
		freeable(tab);
	}
	else if (ac > 2)
		check_arg(av, 1);
	else
		exit(0);
	push_swap(&data, av, ac);
	end(&data);
	return (0);
}
