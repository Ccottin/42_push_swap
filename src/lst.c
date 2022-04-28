/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:56:49 by ccottin           #+#    #+#             */
/*   Updated: 2022/04/28 16:38:02 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_lstlen(t_nbr *list)
{
	t_nbr	*temp;
	int	i;

	i = 0;
	temp = list;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

t_nbr	*ft_lstnew(int nb)
{
	t_nbr	*new;

	new = ft_calloc(sizeof(t_nbr));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->nb = nb;
	return (new);
}

void	ft_add_back(t_nbr **stack, t_nbr *elem)
{
	t_nbr	*temp;

	if (*stack == NULL)
		*stack = elem;
	else
	{
		temp = *stack;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = elem;
	}
}

void	ft_add_front(t_nbr **stack, t_nbr *elem)
{
	if (*stack == NULL)
		elem->next = NULL;
	else
		elem->next = *stack;
	*stack = elem;
}

void	ft_lstclear(t_nbr **stack)
{
	t_nbr	*temp;

	while (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		temp->next = NULL;
		free(temp);
	}
	*stack = NULL;
}
