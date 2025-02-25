/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:40:15 by prichugh          #+#    #+#             */
/*   Updated: 2024/02/26 10:40:15 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (4);
	}
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i - 2);
}

int	ft_putstr_ptr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(nil)", 5);
		return (1);
	}
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i - 2);
}
