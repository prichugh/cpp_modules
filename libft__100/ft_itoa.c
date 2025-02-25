/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:32:06 by prichugh          #+#    #+#             */
/*   Updated: 2024/02/07 12:32:06 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	get_len(int n)
{
	size_t	i;

	i = 1;
	while (n != 0)
	{
		n /= 10;
		if (n != 0)
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
	if (n < 0)
	{
		num = -num;
		len++;
	}
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
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
/*
int main(void)
{
	char *res = ft_itoa(1000);
	printf("result: %s", res);
	free(res);
	return (0);
}
*/
