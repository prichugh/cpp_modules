/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:33:25 by prichugh          #+#    #+#             */
/*   Updated: 2024/08/06 14:33:26 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_map(int *z_line, char *line)
{
	char	**values;
	int		i;

	i = 0;
	values = ft_split(line, ' ');
	while (values[i])
	{
		z_line[i] = ft_atoi(values[i]);
		free(values[i]);
		i++;
	}
	free(values);
}

int	get_height(char *file_name)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (-1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		height++;
	}
	close(fd);
	return (height);
}

int	get_width(char *file_name)
{
	char	*line;
	int		width;
	int		fd;

	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
	{
		close(fd);
		return (0);
	}
	width = count_tokens(line, ' ');
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
	}
	close(fd);
	return (width);
}

void	read_file(char *file_name, t_data *data)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	data->map = (int **)malloc(sizeof(int *) * (data->height + 1));
	while (i < data->height)
	{
		data->map[i] = (int *)malloc(sizeof(int) * (data->width + 1));
		i++;
	}
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		fill_map(data->map[i], line);
		free(line);
		i++;
	}
	close(fd);
	data->map[i] = NULL;
}
