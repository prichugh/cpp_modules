/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:58:26 by prichugh          #+#    #+#             */
/*   Updated: 2024/02/07 15:37:41 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	while (i < len)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}
/*
int main(void)
{
    const char *str = "";
    unsigned int start = 15;
    size_t len = 9;

    char *res = ft_substr(str, start, len);

    if (res == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    printf("Original string: %s\n", str);
    printf("Substring from index %x`u with length %zu: %s\n", start, len, res);

    free(res);

    return (0);
}
*/
