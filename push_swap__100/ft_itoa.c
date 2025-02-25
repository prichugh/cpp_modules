/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:39:53 by prichugh          #+#    #+#             */
/*   Updated: 2024/02/26 10:39:53 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_len(int n)
{
	size_t	i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*result;
	long int	num;
	size_t		len;

	num = n;
	len = get_len(n);
	if (n <= 0)
	{
		num = -num;
		len++;
	}
	result = (char *)malloc(sizeof(char) * (len + 1));
	result[len] = '\0';
	while (len--)
	{
		result[len] = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}
