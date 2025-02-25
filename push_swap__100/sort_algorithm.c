/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:31:04 by prichugh          #+#    #+#             */
/*   Updated: 2024/07/07 12:31:04 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_s *stack_a)
{
	t_s	*current;
	t_s	*next;

	if (!stack_a)
		return (1);
	current = stack_a;
	next = current->next;
	while (next != stack_a)
	{
		if (current->nbr > next->nbr)
			return (0);
		current = next;
		next = current->next;
	}
	return (1);
}

void	rotate_min_to_top(t_s **stack)
{
	t_s	*min_a;
	int	top_or_bot;

	min_a = min_node(*stack);
	top_or_bot = top_or_bottom_per_stack(min_a, *stack);
	if (top_or_bot == 1)
	{
		while ((*stack) != min_a)
			ra(stack);
	}
	else if (top_or_bot == 2)
	{
		while ((*stack) != min_a)
			rra(stack);
	}
}

void	sort_three_numbers(t_s **stack)
{
	t_s	*fir;
	t_s	*sec;
	t_s	*thi;

	fir = *stack;
	sec = fir->next;
	thi = sec->next;
	if (fir->nbr > sec->nbr && sec->nbr < thi->nbr && fir->nbr < thi->nbr)
		sa(stack);
	else if (fir->nbr > sec->nbr && sec->nbr > thi->nbr
		&& fir->nbr > thi->nbr)
	{
		sa(stack);
		rra(stack);
	}
	else if (fir->nbr > sec->nbr && sec->nbr < thi->nbr && fir->nbr > thi->nbr)
		ra(stack);
	else if (fir->nbr < sec->nbr && sec->nbr > thi->nbr
		&& fir->nbr < thi->nbr)
	{
		sa(stack);
		ra(stack);
	}
	else if (fir->nbr < sec->nbr && sec->nbr > thi->nbr && fir->nbr > thi->nbr)
		rra(stack);
}

void	sort_stack_algorithm_cont(t_s **stack_a, t_s **stack_b)
{
	t_s	*correct_spot;
	int	moves;
	int	top_or_bot;

	while (*stack_b != NULL)
	{
		correct_spot = find_correct_spot_in_a(*stack_b, *stack_a);
		top_or_bot = top_or_bottom_per_stack(correct_spot, *stack_a);
		moves = moves_per_stack(correct_spot, *stack_a);
		if (top_or_bot == 1)
		{
			while (moves-- > 0)
				ra(stack_a);
		}
		else if (top_or_bot == 2)
		{
			while (moves-- > 0)
				rra(stack_a);
		}
		pa(stack_a, stack_b);
	}
	rotate_min_to_top(stack_a);
}

void	sort_stack_algorithm(t_s **stack_a, t_s **stack_b)
{
	t_s	*cheapest;
	t_s	*correct_spot;

	if (count_nodes(*stack_a) == 3)
	{
		sort_three_numbers(stack_a);
		return ;
	}
	if ((*stack_a)->nbr > (*stack_a)->next->nbr)
		sa(stack_a);
	if (count_nodes(*stack_a) <= 2)
		return ;
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (count_nodes(*stack_a) > 3)
	{
		cheapest = find_cheapest_to_push(*stack_a, *stack_b);
		correct_spot = find_correct_spot(cheapest, *stack_b);
		move_cheapest(cheapest, stack_a, correct_spot, stack_b);
	}
	sort_three_numbers(stack_a);
	sort_stack_algorithm_cont(stack_a, stack_b);
}
