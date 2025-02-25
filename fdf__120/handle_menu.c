/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:33:16 by prichugh          #+#    #+#             */
/*   Updated: 2024/08/06 15:50:27 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_rect_horizontal(t_img *img, int x, int y, int width)
{
	if (width <= 0)
		return ;
	if (x >= 0 && x < LEN && y >= 0 && y < HEIGHT)
		my_pixel_put(img, x, y, 0x000000);
	draw_rect_horizontal(img, x + 1, y, width - 1);
}

void	draw_rect_vertical(t_img *img, int x, int y, int height)
{
	if (height <= 0)
		return ;
	draw_rect_horizontal(img, x, y, 1);
	draw_rect_vertical(img, x, y + 1, height - 1);
}

void	draw_rect(t_img *img)
{
	int	x;
	int	y;
	int	width;
	int	height;

	x = 20;
	y = 20;
	width = 300;
	height = 200;
	if (height <= 0 || width <= 0)
		return ;
	draw_rect_horizontal(img, x, y, width);
	draw_rect_horizontal(img, x, y + height - 1, width);
	draw_rect_vertical(img, x, y + 1, height - 2);
	draw_rect_vertical(img, x + width - 1, y + 1, height - 2);
}

void	draw_help_menu(t_data *data)
{
	int	x;
	int	y;
	int	color;

	if (!data->help.visible)
		return ;
	x = 20;
	y = 20;
	color = 0xFFFFFF;
	draw_rect(&data->img);
	mlx_string_put(data->mlx_ptr, data->win_ptr, x, y, color, "Controls:");
	y += 20;
	mlx_string_put(data->mlx_ptr, data->win_ptr, x, y, color, "Arrows: Move");
	y += 20;
	mlx_string_put(data->mlx_ptr, data->win_ptr, x, y, color, "W/A/S/D: Spin");
	y += 20;
	mlx_string_put(data->mlx_ptr, data->win_ptr, x, y, color, "Q/E: Turn");
	y += 20;
	mlx_string_put(data->mlx_ptr, data->win_ptr, x, y, color, "+/-: Zoom");
	y += 20;
	mlx_string_put(data->mlx_ptr, data->win_ptr, x, y, color, "R: Reset");
	y += 20;
	mlx_string_put(data->mlx_ptr, data->win_ptr, x, y, color, "ESC: Exit");
	y += 20;
	mlx_string_put(data->mlx_ptr, data->win_ptr, x, y, color, "TAB: Menu");
}

void	handle_help_menu(int keysym, t_data *data)
{
	if (keysym == XK_Tab)
		data->help.visible = !data->help.visible;
}
