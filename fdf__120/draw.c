/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:33:23 by prichugh          #+#    #+#             */
/*   Updated: 2024/08/06 18:32:52 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	redraw_image(t_data *data)
{
	clear_image(&data->img, LEN, HEIGHT, 0x000000);
	draw(data);
	draw_help_menu(data);
}

void	draw_line(t_data *data)
{
	data->x_distance = data->x2 - data->x1;
	data->y_distance = data->y2 - data->y1;
	data->max = max(abs_val(data->x_distance), abs_val(data->y_distance));
	data->x_distance /= data->max;
	data->y_distance /= data->max;
	while ((int)(data->x1 - data->x2) || (int)(data->y1 - data->y2))
	{
		my_pixel_put(&data->img, data->x1, data->y1, data->color);
		data->x1 += data->x_distance;
		data->y1 += data->y_distance;
	}
}

void	draw_horizontal_lines(t_data *data, int y)
{
	int	x;

	x = 0;
	while (x < data->width - 1)
	{
		data->x1 = x;
		data->y1 = y;
		data->x2 = x + 1;
		data->y2 = y;
		bresenham(data);
		x++;
	}
}

void	draw_vertical_lines(t_data *data, int x)
{
	int	y;

	y = 0;
	while (y < data->height - 1)
	{
		data->x1 = x;
		data->y1 = y;
		data->x2 = x;
		data->y2 = y + 1;
		bresenham(data);
		y++;
	}
}

void	draw(t_data *data)
{
	int		x;
	int		y;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;

	y = 0;
	mlx_ptr = data->mlx_ptr;
	win_ptr = data->win_ptr;
	img_ptr = data->img.img_ptr;
	while (y < data->height)
	{
		draw_horizontal_lines(data, y);
		y++;
	}
	x = 0;
	while (x < data->width)
	{
		draw_vertical_lines(data, x);
		x++;
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
}
