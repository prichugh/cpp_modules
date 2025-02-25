/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:33:35 by prichugh          #+#    #+#             */
/*   Updated: 2024/08/06 18:16:12 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset_data(t_data *data)
{
	data->scale = 20.0f;
	data->transform.center_x = 0;
	data->transform.center_y = 0;
	data->transform.angle_x = 0.7f;
	data->transform.angle_y = 0.0f;
	data->transform.angle_z = 0.7f;
	data->scale_factor = 0.1f;
	center_data(data);
	data->shift_x = (LEN / 2.0f) - data->transform.center_x;
	data->shift_y = (HEIGHT / 2.0f) - data->transform.center_y;
}

void	set_data(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->img.img_ptr = NULL;
	data->img.img_pixels_ptr = NULL;
	data->shift_x = 0;
	data->shift_y = 0;
	data->scale = 20.0f;
	data->height = get_height(data->filename);
	data->width = get_width(data->filename);
	data->transform.center_x = 0;
	data->transform.center_y = 0;
	data->map = NULL;
	data->transform.angle_x = 0.7f;
	data->transform.angle_y = 0.0f;
	data->transform.angle_z = 0.7f;
	data->scale_factor = 0.1f;
	data->help.visible = 0;
}

t_data	*init_data(char *filename)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->filename = filename;
	set_data(data);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		free(data);
		return (NULL);
	}
	return (data);
}

void	center_data(t_data *data)
{
	calculate_wireframe_center(data);
	data->shift_x = (LEN / 2.0f) - data->transform.center_x;
	data->shift_y = (HEIGHT / 2.0f) - data->transform.center_y;
}
