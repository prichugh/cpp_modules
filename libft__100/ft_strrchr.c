/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:39:59 by prichugh          #+#    #+#             */
/*   Updated: 2023/11/23 12:39:59 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
/*
int main(void) {
    const char test_string[] = "hello world";
    int search_char = 'l';

	char *ft_result = ft_strrchr(test_string, search_char);
	char *std_result = strrchr(test_string, search_char);
	if (ft_result == std_result)
	{
		printf("\nThe result is the same as strrchr: %p\n\n", ft_result);
	}
	else
	{
		printf("\n	ft_strrchr and strrchr produced different results:\n\n");
		printf("	ft_strrchr result: %p\n", ft_result);
		printf("	strrchr result:   %p\n\n", std_result);
	}
	return 0;
}
*/
