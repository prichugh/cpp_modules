/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:15:25 by prichugh          #+#    #+#             */
/*   Updated: 2024/08/12 14:15:25 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*set_new_line(char *left_c)
{
	int		i;
	int		len;
	char	*new_left_c;

	i = 0;
	len = 0;
	if (left_c == NULL)
		return (NULL);
	while (left_c[len] != '\n' && left_c[len])
		len++;
	if (left_c[len] == '\n')
		len++;
	new_left_c = malloc(sizeof(char) * ft_strlen(left_c) - len + 1);
	if (!new_left_c)
		return (NULL);
	while (left_c[len + i])
	{
		new_left_c[i] = left_c[len + i];
		i++;
	}
	free (left_c);
	new_left_c[i] = 0;
	return (new_left_c);
}

char	*set_line(char *left_c, char *line)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (left_c == NULL)
		return (NULL);
	while (left_c[len] != '\n' && left_c[len])
		len++;
	if (left_c[len] == '\n')
		len++;
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = left_c[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

char	*fill_line_buffer(int fd, char *left_c, char *buffer)
{
	ssize_t		bytes_read;

	bytes_read = 1;
	if (!left_c)
		left_c = ft_strdup("");
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[bytes_read] = 0;
		left_c = ft_strjoin(left_c, buffer);
		if ((ft_strchr(buffer, '\n')))
			break ;
	}
	free (buffer);
	return (left_c);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*left_c;

	line = NULL;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(left_c);
		free(buffer);
		left_c = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	left_c = fill_line_buffer(fd, left_c, buffer);
	if (*left_c == 0)
	{
		free (left_c);
		return (left_c = 0);
	}
	line = set_line(left_c, line);
	left_c = set_new_line(left_c);
	return (line);
}
