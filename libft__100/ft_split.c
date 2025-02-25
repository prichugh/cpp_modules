/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:37:28 by prichugh          #+#    #+#             */
/*   Updated: 2024/02/07 12:37:28 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	safe_malloc(char **array, int position, size_t len)
{
	int	i;

	i = 0;
	array[position] = (char *)malloc(len + 1);
	if (!(array[position]))
	{
		while (i < position)
			free(array[i++]);
		free(array);
		return (1);
	}
	return (0);
}

int	fill(char **array, char const *s, char c)
{
	size_t	len;
	int		position;
	int		i;

	i = 0;
	position = 0;
	while (s[i])
	{
		len = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			len++;
		}
		if (len)
		{
			if (safe_malloc(array, position, len))
				return (1);
			ft_strlcpy(array[position], (char *)(s + i - len), len + 1);
			position++;
		}
	}
	return (0);
}

size_t	count_tokens(char const *s, char c)
{
	size_t	tokens;
	int		inside_tokens;
	int		i;

	i = 0;
	tokens = 0;
	inside_tokens = 1;
	while (s[i])
	{
		inside_tokens = 1;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			if (inside_tokens == 1)
			{
				tokens++;
				inside_tokens = 0;
			}
			i++;
		}
	}
	return (tokens);
}

char	**ft_split(char const *s, char c)
{
	size_t	tokens;
	char	**array;

	tokens = 0;
	if (!s)
		return (NULL);
	tokens = count_tokens(s, c);
	array = (char **)malloc(sizeof(char *) * (tokens + 1));
	if (array == NULL)
		return (NULL);
	array[tokens] = NULL;
	if (fill(array, s, c))
		return (NULL);
	return (array);
}
/*
int	main(void)
{
	char    *s = " Let's see   ";

	char **array = ft_split(s, ' ');

	while (*array)
		printf("%s\n", *array++);
	return (0);
}
*/
