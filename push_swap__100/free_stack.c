/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:17:56 by prichugh          #+#    #+#             */
/*   Updated: 2024/07/07 12:17:56 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_s *stack)
{
	t_s	*temp;

	while (stack)
	{
		temp = stack;
		if (stack->next == stack)
		{
			free(stack);
			break ;
		}
		stack = stack->next;
		temp->prev->next = stack;
		stack->prev = temp->prev;
		free(temp);
	}
}
