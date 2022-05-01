/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:30:40 by ccottin           #+#    #+#             */
/*   Updated: 2022/05/01 19:40:53 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_1(t_data *data, int move)
{
	while (move > 0)
	{
		sa(data, 0);
		ra(data, 0);
		move--;
	}
	ra(data, 0);
}

void	ft_2(t_data *data, int move)
{
	while (move < 0)
	{
		rra(data, 0);
		sa(data, 0);
		move++;
	}
	rra(data, 0);
}
