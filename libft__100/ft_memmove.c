/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:31:15 by prichugh          #+#    #+#             */
/*   Updated: 2024/02/07 12:31:15 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s1;
	unsigned char		*result;

	if (dest == NULL && src == NULL)
		return (NULL);
	s1 = src;
	result = dest;
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	while (n > 0)
	{
		result[n - 1] = s1[n - 1];
		n--;
	}
	return (result);
}
/*
int main()
{
    char buffer[20];

    // Test memmove with overlapping regions (dest > src)
    char str1[] = "Hello, World!";
    memmove(str1 + 7, str1 + 1, 5);
    printf("After moving overlapping regions (dest > src): %s\n", str1);

    // Test memmove with overlapping regions (dest < src)
    char str2[] = "Hello, World!";
    memmove(str2 + 1, str2 + 7, 5);
    printf("After moving overlapping regions (dest < src): %s\n", str2);

    // Test memmove with non-overlapping regions
    char str3[] = "Hello, World!";
    memmove(buffer, str3, strlen(str3) + 1);
    printf("After moving non-overlapping regions: %s\n", buffer);

    return 0;
}
*/
