/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:33:23 by prichugh          #+#    #+#             */
/*   Updated: 2024/08/06 18:29:33 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	adjust_scale(t_data *data, float scale_factor)
{
	float	prev_center_x;
	float	prev_center_y;

	prev_center_x = data->transform.center_x;
	prev_center_y = data->transform.center_y;
	data->scale *= scale_factor;
	calculate_wireframe_center(data);
	data->shift_x += (prev_center_x - data->transform.center_x);
	data->shift_y += (prev_center_y - data->transform.center_y);
}

void	transform_coordinates(t_data *data)
{
	isometric(&data->x1, &data->y1, data->z1 * data->z_scale, data);
	isometric(&data->x2, &data->y2, data->z2 * data->z_scale, data);
	data->x1 += data->shift_x;
	data->x2 += data->shift_x;
	data->y1 += data->shift_y;
	data->y2 += data->shift_y;
}
