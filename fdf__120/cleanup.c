/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:33:49 by prichugh          #+#    #+#             */
/*   Updated: 2024/08/06 18:29:59 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_image(t_img *img, int width, int height, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			my_pixel_put(img, x, y, color);
			x++;
		}
		y++;
	}
}

int	cleanup(t_data *data)
{
	int	i;

	if (data->img.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	if (data->map)
	{
		i = 0;
		while (i < data->height)
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
	}
	free(data);
	ft_printf("Goodbye\n");
	exit(0);
	return (0);
}
