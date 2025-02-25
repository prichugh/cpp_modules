/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_correct_spot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:17:55 by prichugh          #+#    #+#             */
/*   Updated: 2024/07/07 12:17:55 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_s	*find_correct_spot(t_s *node, t_s *stack)
{
	t_s	*current;

	if (node == NULL || stack == NULL)
		return (NULL);
	current = stack;
	if (is_max(node, stack) || is_min(node, stack))
		return (max_node(stack));
	while (1)
	{
		if (node->nbr > current->nbr && node->nbr < current->prev->nbr)
			return (current);
		current = current->next;
		if (current == stack)
			break ;
	}
	return (NULL);
}

t_s	*find_correct_spot_in_a(t_s *node, t_s *stack)
{
	t_s	*current;

	if (node == NULL || stack == NULL)
		return (NULL);
	current = stack;
	if (is_max(node, stack) || is_min(node, stack))
		return (min_node(stack));
	while (1)
	{
		if (node->nbr < current->nbr && node->nbr > current->prev->nbr)
			return (current);
		current = current->next;
		if (current == stack)
			break ;
	}
	return (NULL);
}
