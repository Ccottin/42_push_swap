/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubbles_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:29:19 by ccottin           #+#    #+#             */
/*   Updated: 2022/05/05 15:29:55 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_nbr	*find_small(t_nbr *stack, int small)
{
	t_nbr	*temp;

	temp = stack;
	while (temp->ord != small)
		temp = temp->next;
	return (temp);
}
