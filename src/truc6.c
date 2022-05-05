/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truc6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:32:28 by ccottin           #+#    #+#             */
/*   Updated: 2022/05/05 16:32:58 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	phase_six(t_data *data)
{
	int	big;

	while (get_last(data->stack_a) != data->total - 1)
	{
		check_ss(data);
		rra(data, 0);
	}
	while (data->stack_b != NULL)
	{
		big = find_biggest(data->stack_b);
		if (count_move(data->stack_b, big) < 0)
			do_rrb(data, big);
		else
			do_rb(data, big);
		check_ss(data);
	}
}
