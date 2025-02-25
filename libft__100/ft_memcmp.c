/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:37:36 by prichugh          #+#    #+#             */
/*   Updated: 2023/11/23 12:37:36 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const char *s1, const char *s2, size_t n)
{
	size_t					i;
	const unsigned char		*d1;
	const unsigned char		*d2;

	i = 0;
	d1 = (const unsigned char *)s1;
	d2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (d1[i] != d2[i])
			return (d1[i] - d2[i]);
		i++;
	}
	return (0);
}
/*
int main(void)
{
	char s1[] = "Happy birthday to you, Happy birthday to you";
	char s2[] = "Happy birthday dear 42 ";

	int result = ft_memcmp(s1, s2, 24);
	printf("\nResult: %d\n", result);
	return (0);
}
*/
