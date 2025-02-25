/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_range.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:37:49 by prichugh          #+#    #+#             */
/*   Updated: 2024/08/11 16:48:24 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_int_range(char *nbr, int *values)
{
	int	i;

	i = 0;
	if (!int_range(&nbr[i]))
	{
		free(values);
		return (1);
	}
	return (0);
}

long long	int_in_range(const char *str)
{
	int			i;
	int			neg;
	long long	res;

	i = 0;
	neg = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * neg);
}

int	int_range(char *split_args)
{
	long long	i;

	i = int_in_range(split_args);
	if (i > 2147483647 || i < -2147483648)
		return (0);
	return (1);
}
