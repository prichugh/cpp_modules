/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:37:22 by prichugh          #+#    #+#             */
/*   Updated: 2023/11/23 12:37:22 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	const unsigned char		*d;

	i = 0;
	d = s;
	while (i < n)
	{
		if (d[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
    const char test_string[] = "hello world";
    int search_char = 'l';
	int n = 5;

	char *ft_result = ft_memchr(test_string, search_char, n);
	char *std_result = memchr(test_string, search_char, n);
	if (ft_result == std_result)
	{
		printf("\nft_memchr and memchr are the same: %p\n\n", ft_result);
	}
	else
	{
		printf("\n	ft_memchr and memchr are different:\n\n");
		printf("	ft_memchr result: %p\n", ft_result);
		printf("	memchr result:   %p\n\n", std_result);
	}
	return 0;
}
*/
