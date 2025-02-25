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

#include "fdf.h"

int	safe_malloc(char **array, int position, size_t len)
{
	int	i;

	i = 0;
	array[position] = malloc(len + 1);
	if (!(array[position]))
	{
		while (i <= position)
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

	position = 0;
	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			s++;
			len++;
		}
		if (len > 0)
		{
			if (safe_malloc(array, position, len))
				return (1);
			ft_strlcpy(array[position], (char *)(s - len), len + 1);
			position++;
		}
	}
	array[position] = NULL;
	return (0);
}

size_t	count_tokens(char const *s, char c)
{
	size_t	tokens;
	int		inside_tokens;

	tokens = 0;
	inside_tokens = 1;
	while (*s)
	{
		inside_tokens = 1;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			if (inside_tokens == 1)
			{
				tokens++;
				inside_tokens = 0;
			}
			s++;
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
	if (*s == '\0' || count_tokens(s, c) == 0)
	{
		array = malloc(sizeof(char *));
		if (!array)
			return (NULL);
		array[0] = NULL;
		return (array);
	}
	tokens = count_tokens(s, c);
	array = (char **)malloc(sizeof(char *) * (tokens + 1));
	if (array == NULL)
		return (NULL);
	array[tokens] = NULL;
	if (fill(array, s, c))
		return (NULL);
	return (array);
}
