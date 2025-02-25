/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:33:44 by prichugh          #+#    #+#             */
/*   Updated: 2024/08/06 17:54:46 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(float *x, float *y, int z, t_data *data)
{
	float	x_rot_z;
	float	y_rot_z;
	float	x_rot_y;
	float	z_rot_y;
	float	y_rot_x;

	*x -= data->transform.center_x;
	*y -= data->transform.center_y;
	x_rot_z = *x * cos(data->transform.angle_z) - *y
		* sin(data->transform.angle_z);
	y_rot_z = *x * sin(data->transform.angle_z) + *y
		* cos(data->transform.angle_z);
	x_rot_y = x_rot_z * cos(data->transform.angle_y) + z
		* sin(data->transform.angle_y);
	z_rot_y = -x_rot_z * sin(data->transform.angle_y) + z
		* cos(data->transform.angle_y);
	y_rot_x = y_rot_z * cos(data->transform.angle_x) - z_rot_y
		* sin(data->transform.angle_x);
	z = y_rot_z * sin(data->transform.angle_x) + z_rot_y
		* cos(data->transform.angle_x);
	*x = x_rot_y + data->transform.center_x;
	*y = y_rot_x + data->transform.center_y;
}

void	init_bresenham_vars(t_data *data)
{
	data->z1 = data->map[(int)data->y1][(int)data->x1];
	data->z2 = data->map[(int)data->y2][(int)data->x2];
	data->x1 *= data->scale;
	data->x2 *= data->scale;
	data->y1 *= data->scale;
	data->y2 *= data->scale;
	data->z_scale = data->scale * data->scale_factor;
}

void	bresenham(t_data *data)
{
	init_bresenham_vars(data);
	set_color(data->z1, data->z2, data);
	transform_coordinates(data);
	draw_line(data);
}
