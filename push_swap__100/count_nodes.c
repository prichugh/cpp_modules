/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:17:39 by prichugh          #+#    #+#             */
/*   Updated: 2024/07/07 12:17:39 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_nodes(t_s *stack)
{
	t_s	*current;
	int	count;

	count = 0;
	if (stack == NULL)
		return (0);
	current = stack;
	while (1)
	{
		count++;
		current = current->next;
		if (current == stack)
			break ;
	}
	return (count);
}
