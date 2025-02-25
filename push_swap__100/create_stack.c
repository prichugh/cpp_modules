/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:17:52 by prichugh          #+#    #+#             */
/*   Updated: 2024/07/07 12:17:52 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**get_args(int argc, char *argv[])
{
	char	**args;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args || !args[0])
		{
			if (args)
				free(args);
			error_msg();
		}
	}
	else
		args = argv + 1;
	return (args);
}

void	initialize_stack(char **arg, t_s **stack_a, int argc)
{
	int	i;
	t_s	*new_node;

	i = 0;
	while (arg[i])
	{
		if (ft_strncmp(arg[i], "+", 2) == 0 || ft_strncmp(arg[i], "-", 2) == 0)
		{
			free_args(arg);
			error_msg();
		}
		new_node = set_new_node(ft_atoi2(arg[i], arg, *stack_a, argc));
		if (!new_node)
			error_msg();
		if (is_duplicate(new_node, stack_a))
			error_msg();
		append(stack_a, new_node);
		i++;
	}
}

t_s	*set_new_node(long content)
{
	t_s	*new_node;

	new_node = malloc(sizeof(t_s));
	if (!new_node)
		return (NULL);
	new_node->nbr = content;
	new_node->next = new_node;
	new_node->prev = new_node;
	return (new_node);
}

void	append(t_s **stack, t_s *new_node)
{
	t_s	*last;

	if (*stack == NULL)
		*stack = new_node;
	else
	{
		last = (*stack)->prev;
		last->next = new_node;
		new_node->prev = last;
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
}
