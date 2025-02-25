/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:38:55 by prichugh          #+#    #+#             */
/*   Updated: 2023/11/23 12:38:55 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		n;
	char	*dest;

	i = 0;
	n = 0;
	while (src[n])
		n++;
	dest = (char *)malloc(sizeof(*dest) * n + 1);
	if (!dest)
		return (NULL);
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int main(void)
{
    const char *original = "Hello, this is a test!";
    char *duplicate = ft_strdup(original);

    if (duplicate != NULL)
    {
        printf("Original string: %s\n", original);
        printf("Duplicate string: %s\n", duplicate);

        // Don't forget to free the allocated memory
        free(duplicate);
    }
    else
    {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
*/
