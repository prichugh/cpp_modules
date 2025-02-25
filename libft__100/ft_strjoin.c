/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:30:34 by prichugh          #+#    #+#             */
/*   Updated: 2024/02/07 16:40:10 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	c;
	size_t	n;
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	c = ft_strlen(s1);
	n = ft_strlen(s2);
	result = ((char *)malloc(sizeof(char) * (c + n + 1)));
	if (!result)
		return (NULL);
	while (s1[j])
		result[i++] = s1[j++];
	j = 0;
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	return ((char *) result);
}
/*
int main (void)
{
	char s1[] = "heloooooo ";
	char s2[] = "woooooorld";
	char *result;

	result = ft_strjoin(s1, s2);
	printf ("Result: %s", result);
	free (result);
	return (0);
}
*/
