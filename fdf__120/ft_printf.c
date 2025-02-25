/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:39:56 by prichugh          #+#    #+#             */
/*   Updated: 2024/02/26 10:39:56 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		while (format[i] != '%' && format[i] != '\0')
		{
			write(1, &format[i], 1);
			i++;
		}
		if (format[i] == '%')
		{
			i++;
			count += check_type(format, i, args);
			i++;
		}
	}
	va_end (args);
	return (i + count);
}
