/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_stack_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:18:01 by prichugh          #+#    #+#             */
/*   Updated: 2024/07/07 12:18:01 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_cont(t_s *top_a, t_s *top_b, t_s **stack_b)
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

void	pb(t_s **stack_a, t_s **stack_b)
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
	pb_cont(top_a, top_b, stack_b);
	write(1, "pb\n", 3);
}

void	sb(t_s **stack)
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
	write(1, "sb\n", 3);
}

void	rb(t_s **stack_b)
{
	if (*stack_b != NULL && (*stack_b)->next != *stack_b)
		*stack_b = (*stack_b)->next;
	write(1, "rb\n", 3);
}

void	rrb(t_s **stack_b)
{
	if (*stack_b != NULL && (*stack_b)->next != *stack_b)
		*stack_b = (*stack_b)->prev;
	write(1, "rrb\n", 4);
}
