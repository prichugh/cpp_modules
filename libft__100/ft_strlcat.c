/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:52:32 by prichugh          #+#    #+#             */
/*   Updated: 2023/11/23 18:31:49 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_size;
	size_t	src_size;

	i = 0;
	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	if (size <= dest_size)
		return (src_size + size);
	while (src[i] != '\0' && (dest_size + i) < (size - 1))
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = '\0';
	return (src_size + dest_size);
}

/*
int main()
{
	char s[] = "lorem";
	char d[11] = "a";
	unsigned int	size = ft_strlcat(d, s, 15);
	printf("\nTotal Size: %i\n\n", size);
	printf("Final string: %s\n\n", d);
	return (0);
}
*/
