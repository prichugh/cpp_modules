/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:18:07 by prichugh          #+#    #+#             */
/*   Updated: 2024/07/07 12:18:07 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_cheapest(t_s *chpst, t_s **st_a, t_s *cor, t_s **st_b)
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
	top_or_bot = top_or_bottom(chpst, *st_a, cor, *st_b);
	if (top_or_bot == 1)
	{
		moves_a = moves_per_stack(chpst, *st_a);
		moves_b = moves_per_stack(cor, *st_b);
		moves_together = moves_b;
		moves_separate = moves_a - moves_b;
		while (moves_together-- > 0)
			rr(st_a, st_b);
		while (moves_separate-- > 0)
			ra(st_a);
	}
	else
		move_cheapest_cont2(chpst, st_a, cor, st_b);
	pb(st_a, st_b);
}

void	move_cheapest_cont2(t_s *ch, t_s **st_a, t_s *cor, t_s **st_b)
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
	top_or_bot = top_or_bottom(ch, *st_a, cor, *st_b);
	if (top_or_bot == 2)
	{
		moves_a = moves_per_stack(ch, *st_a);
		moves_b = moves_per_stack(cor, *st_b);
		moves_together = moves_a;
		moves_separate = moves_b - moves_a;
		while (moves_together-- > 0)
			rr(st_a, st_b);
		while (moves_separate-- > 0)
			rb(st_b);
	}
	else
		move_cheapest_cont3(ch, st_a, cor, st_b);
}

void	move_cheapest_cont3(t_s *ch, t_s **st_a, t_s *cor, t_s **st_b)
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
	top_or_bot = top_or_bottom(ch, *st_a, cor, *st_b);
	if (top_or_bot == 3)
	{
		moves_a = moves_per_stack(ch, *st_a);
		moves_b = moves_per_stack(cor, *st_b);
		moves_together = moves_b;
		moves_separate = moves_a - moves_b;
		while (moves_together-- > 0)
			rrr(st_a, st_b);
		while (moves_separate-- > 0)
			rra(st_a);
	}
	else
		move_cheapest_cont4(ch, st_a, cor, st_b);
}
