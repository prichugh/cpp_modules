/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:40:12 by prichugh          #+#    #+#             */
/*   Updated: 2024/02/26 10:40:12 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_ptrhexlen(unsigned long int n)
{
	size_t	i;

	i = 0;
	while (n != 0)
	{
		i++;
		n = n / 16;
	}
	return (i);
}

char	*ft_putptr(void *ptr)
{
	char				*result;
	unsigned long int	num;
	int					digit;
	size_t				len;

	num = (long)ptr;
	if (num == 0)
	{
		return (NULL);
	}
	ft_putstr("0x");
	len = get_ptrhexlen(num);
	result = (char *)malloc(sizeof(char) * (len + 1));
	result[len] = '\0';
	while (len--)
	{
		result[len] = '0';
		digit = num % 16;
		if (digit < 10)
			result[len] += digit;
		else
			result[len] = digit + 'a' - 10;
		num /= 16;
	}
	return (result);
}
