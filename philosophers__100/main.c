/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:49:15 by prichugh          #+#    #+#             */
/*   Updated: 2024/09/09 12:49:15 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_number(char *argv)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while ((argv[i] >= 9 && argv[i] <= 13) || argv[i] == 32)
		i++;
	while (argv[i] == '-' || argv[i] == '+')
	{
		if (argv[i] == '-')
			sign *= -1;
		i++;
	}
	if (sign < 0)
		return (-1);
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_argc(int argc)
{
	if (argc < 5)
	{
		printf("[error]\nToo few args\n");
		return (0);
	}
	else if (argc > 6)
	{
		printf("[error]\nToo many args\n");
		return (0);
	}
	return (1);
}

int	is_valid_argv(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) <= 0)
		{
			printf("[error]\nInput must be a number greater than zero\n");
			return (0);
		}
		else if (!is_number(argv[i]))
		{
			printf("[error]\nInput must be valid numbers\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (!is_valid_argv(argv) || !is_valid_argc(argc))
		return (1);
	init_data(argc, argv);
	return (0);
}
