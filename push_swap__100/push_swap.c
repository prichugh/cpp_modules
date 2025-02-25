/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:08:15 by prichugh          #+#    #+#             */
/*   Updated: 2024/07/07 15:08:15 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_integer(const char *str)
{
	if (*str == '\0')
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (!is_digit((unsigned char)*str))
			return (0);
		str++;
	}
	return (1);
}

void	check_split_args(char **split_args)
{
	int	j;

	j = 0;
	while (split_args[j])
	{
		if (!is_valid_integer(split_args[j]))
		{
			free_args(split_args);
			error_msg();
		}
		j++;
	}
	if (duplicate(split_args))
	{
		free_args(split_args);
		error_msg();
	}
	free_args(split_args);
}

static void	process_single_argument(char *arg)
{
	char	**split_args;

	split_args = ft_split(arg, ' ');
	if (!split_args || !split_args[0])
	{
		if (split_args)
			free_args(split_args);
		error_msg();
	}
	check_split_args(split_args);
}

void	verify_args(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc == 2)
		process_single_argument(argv[1]);
	else
	{
		while (i < argc)
		{
			ft_atoi2(argv[i], argv, NULL, argc);
			if (!is_valid_integer(argv[i]))
				error_msg();
			i++;
		}
		if (duplicate(argv + 1))
			error_msg();
	}
}

int	main(int argc, char *argv[])
{
	t_s		*stack_a;
	t_s		*stack_b;
	char	**args;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	verify_args(argc, argv);
	args = get_args(argc, argv);
	if (!args)
		return (0);
	initialize_stack(args, &stack_a, argc);
	if (check_sorted(stack_a))
	{
		free_stack(stack_a);
		if (argc == 2)
			free_args(args);
		return (0);
	}
	sort_stack_algorithm(&stack_a, &stack_b);
	free_stack(stack_a);
	if (argc == 2)
		free_args(args);
	return (0);
}
