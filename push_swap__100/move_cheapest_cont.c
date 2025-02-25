/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cheapest_cont.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:18:04 by prichugh          #+#    #+#             */
/*   Updated: 2024/07/07 12:18:04 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_cheapest_cont4(t_s *chpst, t_s **stack_a, t_s *cor, t_s **stack_b)
{
	int	top_or_bot;
	int	moves_a;
	int	moves_b;
	int	moves_together;
	int	moves_separate;

	moves_a = 0;
	moves_b = 0;
	moves_together = 0;
	moves_separate = 0;
	top_or_bot = top_or_bottom(chpst, *stack_a, cor, *stack_b);
	if (top_or_bot == 4)
	{
		moves_a = moves_per_stack(chpst, *stack_a);
		moves_b = moves_per_stack(cor, *stack_b);
		moves_together = moves_a;
		moves_separate = moves_b - moves_a;
		while (moves_together-- > 0)
			rrr(stack_a, stack_b);
		while (moves_separate-- > 0)
			rrb(stack_b);
	}
	else
		move_cheapest_cont5(chpst, stack_a, cor, stack_b);
}

void	move_cheapest_cont5(t_s *chpst, t_s **stack_a, t_s *cor, t_s **stack_b)
{
	int	top_or_bot;
	int	moves_a;
	int	moves_b;

	moves_a = 0;
	moves_b = 0;
	top_or_bot = top_or_bottom(chpst, *stack_a, cor, *stack_b);
	if (top_or_bot == 5)
	{
		moves_a = moves_per_stack(chpst, *stack_a);
		moves_b = moves_per_stack(cor, *stack_b);
		while (moves_a-- > 0)
			ra(stack_a);
		while (moves_b-- > 0)
			rrb(stack_b);
	}
	else
		move_cheapest_cont6(chpst, stack_a, cor, stack_b);
}

void	move_cheapest_cont6(t_s *chpst, t_s **stack_a, t_s *cor, t_s **stack_b)
{
	int	top_or_bot;
	int	moves_a;
	int	moves_b;

	moves_a = 0;
	moves_b = 0;
	top_or_bot = top_or_bottom(chpst, *stack_a, cor, *stack_b);
	if (top_or_bot == 6)
	{
		moves_a = moves_per_stack(chpst, *stack_a);
		moves_b = moves_per_stack(cor, *stack_b);
		while (moves_a-- > 0)
			rra(stack_a);
		while (moves_b-- > 0)
			rb(stack_b);
	}
}
