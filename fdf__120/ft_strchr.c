/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:56:12 by prichugh          #+#    #+#             */
/*   Updated: 2024/08/08 17:25:45 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strchr(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == c)
		return ((char *)s);
	return (NULL);
}
/*
int main() {
    char s[] = "Everyone asks where is waldo, not how is waldo :(";
    char search_char = 'y';

    char *result = ft_strchr(s, search_char);

    if (result != NULL) {
		printf("\nString: %s", s);
        printf("\n\nCharacter '%c' found at position: %ld\n\n",
		search_char, result - s);
    } else {
		printf("\nString: %s", s);
        printf("\n\nCharacter '%c' not found in the string.\n\n", search_char);
    }

    return 0;
}
*/
