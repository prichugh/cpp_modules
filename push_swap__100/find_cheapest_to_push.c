/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest_to_push.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:18:25 by prichugh          #+#    #+#             */
/*   Updated: 2024/07/07 12:18:25 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	number_of_moves_cont(t_distance *d, int torb)
{
	int	moves;

	moves = 0;
	if (torb == 1)
		moves = d->top_a;
	else if (torb == 2)
		moves = d->top_b;
	else if (torb == 3)
		moves = d->bot_a;
	else if (torb == 4)
		moves = d->bot_b;
	else if (torb == 5)
		moves = d->top_a + d->bot_b;
	else if (torb == 6)
		moves = d->bot_a + d->top_b;
	return (moves);
}

int	number_of_moves(t_s *current, t_s *stack_a, t_s *correct, t_s *stack_b)
{
	int			moves;
	int			top_or_bot;
	t_distance	*d;

	d = malloc(sizeof(t_distance));
	if (d == NULL)
	{
		return (-1);
	}
	moves = 0;
	top_or_bot = 0;
	d->top_a = node_index(current, stack_a);
	d->bot_a = node_index_reverse(current, stack_a);
	d->top_b = node_index(correct, stack_b);
	d->bot_b = node_index_reverse(correct, stack_b);
	top_or_bot = top_or_bottom(current, stack_a, correct, stack_b);
	moves = number_of_moves_cont(d, top_or_bot);
	free(d);
	return (moves + 1);
}

int	moves_per_stack(t_s *node, t_s *stack)
{
	int	top;
	int	bot;
	int	moves;

	moves = 0;
	top = node_index(node, stack);
	bot = node_index_reverse(node, stack);
	if (top <= bot)
		moves = top;
	else if (bot < top)
		moves = bot;
	return (moves);
}

t_s	*find_cheapest_to_push(t_s *stack_a, t_s *stack_b)
{
	t_s	*current;
	t_s	*correct_spot;
	t_s	*cheapest;
	int	moves;
	int	new_moves;

	new_moves = 0;
	current = stack_a;
	cheapest = current;
	correct_spot = find_correct_spot(current, stack_b);
	moves = number_of_moves(current, stack_a, correct_spot, stack_b);
	current = current->next;
	while (current != stack_a)
	{
		correct_spot = find_correct_spot(current, stack_b);
		new_moves = number_of_moves(current, stack_a, correct_spot, stack_b);
		if (new_moves < moves)
		{
			cheapest = current;
			moves = new_moves;
		}
		current = current->next;
	}
	return (cheapest);
}
