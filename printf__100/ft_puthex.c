/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:40:10 by prichugh          #+#    #+#             */
/*   Updated: 2024/02/26 10:40:10 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_hexlen(unsigned int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		i++;
		n = n / 16;
	}
	return (i);
}

char	*ft_puthex(unsigned int n, const char format)
{
	char		*result;
	long int	num;
	int			digit;
	size_t		len;

	num = n;
	len = get_hexlen(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	result[len] = '\0';
	while (len > 0)
	{
		len--;
		digit = num % 16;
		if (digit < 10)
			result[len] = digit + '0';
		else
		{
			if (format == 'x')
				result[len] = digit - 10 + 'a';
			else if (format == 'X')
				result[len] = digit - 10 + 'A';
		}
		num /= 16;
	}
	return (result);
}
