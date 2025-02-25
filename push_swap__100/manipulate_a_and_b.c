/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_a_and_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:17:57 by prichugh          #+#    #+#             */
/*   Updated: 2024/07/07 12:17:57 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_s **stack_a, t_s **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	rr(t_s **stack_a, t_s **stack_b)
{
	if (*stack_a != NULL && (*stack_a)->next != *stack_a)
		*stack_a = (*stack_a)->next;
	if (*stack_b != NULL && (*stack_b)->next != *stack_b)
		*stack_b = (*stack_b)->next;
	write(1, "rr\n", 3);
}

void	rrr(t_s **stack_a, t_s **stack_b)
{
	if (*stack_a != NULL && (*stack_a)->next != *stack_a)
		*stack_a = (*stack_a)->prev;
	if (*stack_b != NULL && (*stack_b)->next != *stack_b)
		*stack_b = (*stack_b)->prev;
	write(1, "rrr\n", 4);
}
