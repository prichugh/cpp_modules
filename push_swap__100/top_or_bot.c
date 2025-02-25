/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_or_bot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:18:14 by prichugh          #+#    #+#             */
/*   Updated: 2024/07/07 12:18:14 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	top_or_bottom_cont(int top_a, int bot_a, int top_b, int bot_b)
{
	int	top_or_bot;

	top_or_bot = 0;
	if ((top_a <= bot_a) && (top_b <= bot_b))
	{
		if (top_a >= top_b)
			top_or_bot = 1;
		else if (top_a < top_b)
			top_or_bot = 2;
	}
	else if ((bot_a <= top_a) && (bot_b <= top_b))
	{
		if (bot_a >= bot_b)
			top_or_bot = 3;
		else if (bot_b > bot_a)
			top_or_bot = 4;
	}
	else if ((top_a < bot_a) && (bot_b < top_b))
		top_or_bot = 5;
	else if ((bot_a < top_a) && (top_b < bot_b))
		top_or_bot = 6;
	return (top_or_bot);
}

int	top_or_bottom(t_s *curr, t_s *stack_a, t_s *corr, t_s *stack_b)
{
	int	top_a;
	int	bot_a;
	int	top_b;
	int	bot_b;
	int	top_or_bot;

	top_or_bot = 0;
	top_a = node_index(curr, stack_a);
	bot_a = node_index_reverse(curr, stack_a);
	top_b = node_index(corr, stack_b);
	bot_b = node_index_reverse(corr, stack_b);
	top_or_bot = top_or_bottom_cont (top_a, bot_a, top_b, bot_b);
	return (top_or_bot);
}

int	top_or_bottom_per_stack(t_s *node, t_s *stack)
{
	int	top;
	int	bot;

	top = node_index(node, stack);
	bot = node_index_reverse(node, stack);
	if (top <= bot)
		return (1);
	else if (bot < top)
		return (2);
	return (0);
}
