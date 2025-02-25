/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:17:11 by prichugh          #+#    #+#             */
/*   Updated: 2024/07/07 12:17:11 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cleanup(t_s *stack, char **arg, int argc)
{
	if (argc == 2)
		free_args(arg);
	free_stack(stack);
	error_msg();
}

int	ft_atoi2(const char *str, char **arg, t_s *stack, int argc)
{
	int				neg;
	long long int	i;

	i = 0;
	neg = 1;
	while (*str >= 9 && *str <= 13)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str)
	{
		i = i * 10 + (*str - '0');
		str++;
	}
	if ((neg * i) > 2147483647 || (neg * i) < -2147483648)
		cleanup(stack, arg, argc);
	return ((int)(neg * i));
}
