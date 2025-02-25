/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:40:18 by prichugh          #+#    #+#             */
/*   Updated: 2024/02/26 10:40:18 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_len(unsigned int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	char		*result;
	size_t		len;
	long int	num;

	num = n;
	len = get_len(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	result[len] = '\0';
	while (len--)
	{
		result[len] = (n % 10) + '0';
		n /= 10;
	}
	return (result);
}
