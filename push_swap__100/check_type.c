/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:39:48 by prichugh          #+#    #+#             */
/*   Updated: 2024/02/26 10:39:48 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type_cont(const char *format, int i, va_list args)
{
	int		count;
	char	*res;

	count = 0;
	if (format[i] == 'X' || format[i] == 'x')
	{
		res = ft_puthex(va_arg(args, unsigned int), format[i]);
		count += ft_putstr(res);
		free(res);
	}
	else if (format[i] == '%')
	{
		write(1, "%", 1);
		count--;
	}
	return (count);
}

int	check_type_continued(const char *format, int i, va_list args)
{
	int		count;
	char	*res;

	count = 0;
	if (format[i] == 'd' || format[i] == 'i')
	{
		res = ft_itoa(va_arg(args, int));
		count += ft_putstr(res);
		free(res);
	}
	else if (format[i] == 'u')
	{
		res = ft_uitoa(va_arg(args, unsigned int));
		count += ft_putstr(res);
		free(res);
	}
	else
		count += check_type_cont(format, i, args);
	return (count);
}

int	check_type(const char *format, int i, va_list args)
{
	int		count;
	char	*res;

	count = 0;
	if (format[i] == 'c')
	{
		ft_putchar(va_arg(args, int));
		count--;
	}
	else if (format[i] == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (format[i] == 'p')
	{
		res = ft_putptr(va_arg(args, void *));
		count += ft_putstr_ptr(res);
		count += 2;
		free(res);
	}
	else
		count += check_type_continued(format, i, args);
	return (count);
}
