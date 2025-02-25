/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:38:30 by prichugh          #+#    #+#             */
/*   Updated: 2024/02/07 12:51:17 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (src[i])
		i++;
	return (i);
}
/*
int main()
{
	char s[] = "hello world, this is your boy prince";
	char d[20];
	int len = 21;
	unsigned int 	size = ft_strlcpy(d, s, len);

	printf("\nSize of source: %i\n\n", size);
	printf("%i characters written out: %s\n\n", len, d);
	return (0);
}
*/
