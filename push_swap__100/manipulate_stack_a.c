/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_stack_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:17:59 by prichugh          #+#    #+#             */
/*   Updated: 2024/07/07 12:17:59 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_s **stack)
{
	t_s	*first;
	t_s	*second;

	if (*stack == NULL || (*stack)->next == *stack)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next->prev = first;
	second->next = first;
	second->prev = first->prev;
	first->prev->next = second;
	first->prev = second;
	*stack = second;
	write(1, "sa\n", 3);
}

void	pa_cont(t_s *top_b, t_s *top_a, t_s **stack_b)
{
	if (top_b == NULL)
	{
		top_a->next = top_a;
		top_a->prev = top_a;
		*stack_b = top_a;
	}
	else
	{
		top_a->next = top_b;
		top_a->prev = top_b->prev;
		top_b->prev->next = top_a;
		top_b->prev = top_a;
		*stack_b = top_a;
	}
}

void	pa(t_s **stack_b, t_s **stack_a)
{
	t_s	*top_a;
	t_s	*top_b;

	if (*stack_a == NULL)
		return ;
	top_a = *stack_a;
	top_b = *stack_b;
	if (top_a->next == top_a)
	{
		*stack_a = NULL;
	}
	else
	{
		top_a->next->prev = top_a->prev;
		top_a->prev->next = top_a->next;
		*stack_a = top_a->next;
	}
	pa_cont(top_b, top_a, stack_b);
	write(1, "pa\n", 3);
}

void	ra(t_s **stack_a)
{
	if (*stack_a != NULL && (*stack_a)->next != *stack_a)
		*stack_a = (*stack_a)->next;
	write(1, "ra\n", 3);
}

void	rra(t_s **stack_a)
{
	if (*stack_a != NULL && (*stack_a)->next != *stack_a)
		*stack_a = (*stack_a)->prev;
	write(1, "rra\n", 4);
}
