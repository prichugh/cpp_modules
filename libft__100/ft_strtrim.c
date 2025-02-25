/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:47:47 by prichugh          #+#    #+#             */
/*   Updated: 2024/02/07 11:47:47 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	front(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (!(ft_strchr(set, s1[i])))
			break ;
		i++;
	}
	return (i);
}

size_t	end(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1);
	while (i > 0 && (ft_strrchr(set, s1[i - 1])))
	{
		if (!(ft_strrchr(set, s1[i - 1])))
			break ;
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	finish;

	start = front(s1, set);
	finish = end(s1, set);
	if (!s1)
		return (NULL);
	if (start >= finish)
		return (ft_strdup(""));
	return (ft_substr(s1, start, finish - start));
}
/*
int main()
{
	int i = 0;
	const char	test[] = "ACBABBACBCABCBAJKLMNBBCABCBACBBBACBACBBCA";
	const char	*remove = "BACBABC";
	char	*result;
	result = ft_strtrim(test, remove);

	printf("input = %s\n", test);
	printf("Result = %s", result);
	free (result);

	return 0;
}
*/
