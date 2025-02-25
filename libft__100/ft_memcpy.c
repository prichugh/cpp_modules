/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:14:26 by prichugh          #+#    #+#             */
/*   Updated: 2024/02/07 14:42:49 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	i = 0;
	if (!dest && !src)
		return (dest);
	while (i != n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
/*
int main()
{
	int	i = 0;
	int	c = 11;
	char	s[] = "hello world, this is ya boy prince";
	char	d[20];
	char	*test = memcpy(d, s, 11);

	ft_memcpy(d, s, 11);
	while (i != c)
	{
		printf("%c", d[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i != c)
	{
		printf("%c", test[i]);
		i++;
	}
	printf("\n");
	return (0);
}
*/
