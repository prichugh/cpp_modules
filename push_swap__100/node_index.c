/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:18:05 by prichugh          #+#    #+#             */
/*   Updated: 2024/07/07 12:18:05 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	node_index(t_s *node, t_s *stack)
{
	int	i;
	t_s	*current;

	if (node == NULL || stack == NULL)
		return (0);
	i = 0;
	current = stack;
	while (1)
	{
		if (current == node)
			return (i);
		i++;
		current = current->next;
		if (current == stack)
			break ;
	}
	return (0);
}

int	node_index_reverse(t_s *node, t_s *stack)
{
	int	i;
	t_s	*current;

	if (node == NULL || stack == NULL)
		return (0);
	i = 1;
	current = stack->prev;
	while (1)
	{
		if (current == node)
			return (i);
		i++;
		current = current->prev;
		if (current == stack->prev)
			break ;
	}
	return (0);
}
