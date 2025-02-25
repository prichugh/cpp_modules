/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_and_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:18:03 by prichugh          #+#    #+#             */
/*   Updated: 2024/07/07 12:18:03 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_max(t_s *node, t_s *stack)
{
	t_s	*current;

	if (node == NULL || stack == NULL)
		return (0);
	current = stack;
	while (1)
	{
		if (node->nbr <= current->nbr)
			return (0);
		current = current->next;
		if (current == stack)
			break ;
	}
	return (1);
}

int	is_min(t_s *node, t_s *stack)
{
	t_s	*current;

	if (node == NULL || stack == NULL)
		return (0);
	current = stack;
	while (1)
	{
		if (node->nbr >= current->nbr)
			return (0);
		current = current->next;
		if (current == stack)
			break ;
	}
	return (1);
}

t_s	*max_node(t_s *stack)
{
	t_s	*max;
	t_s	*current;

	if (stack == NULL)
		return (NULL);
	current = stack->next;
	max = stack;
	while (current != stack)
	{
		if (current->nbr > max->nbr)
			max = current;
		current = current->next;
	}
	return (max);
}

t_s	*min_node(t_s *stack)
{
	t_s	*min;
	t_s	*current;

	if (stack == NULL)
		return (NULL);
	current = stack->next;
	min = stack;
	while (current != stack)
	{
		if (current->nbr < min->nbr)
			min = current;
		current = current->next;
	}
	return (min);
}
