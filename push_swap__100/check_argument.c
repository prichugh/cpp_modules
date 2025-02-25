/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:17:30 by prichugh          #+#    #+#             */
/*   Updated: 2024/07/07 12:17:30 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(int *values, int count, int value)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (values[i] == value)
		{
			free (values);
			return (1);
		}
		i++;
	}
	return (0);
}

int	duplicate(char **args)
{
	int	i;
	int	count;
	int	*values;
	int	value;

	i = 0;
	count = 0;
	values = malloc(sizeof(int) * 1000);
	if (!values)
		error_msg();
	while (args[i])
	{
		if (validate_int_range(args[i], values))
			return (0);
		value = ft_atoi2(args[i], NULL, NULL, 0);
		if (check_duplicate(values, count, value))
			return (1);
		values[count] = value;
		count++;
		i++;
	}
	free(values);
	return (0);
}

int	is_duplicate(t_s *new_node, t_s **stack)
{
	t_s	*current;

	if (*stack == NULL)
		return (0);
	current = *stack;
	if (current->nbr == new_node->nbr)
	{
		return (1);
		free(new_node);
	}
	current = current->next;
	while (*stack != current)
	{
		if (current->nbr == new_node->nbr)
		{
			return (1);
			free(new_node);
		}
		current = current->next;
	}
	return (0);
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_numeric(const char *str)
{
	if (!str)
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (!is_digit(*str))
			return (0);
		str++;
	}
	return (1);
}
