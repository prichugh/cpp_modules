/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:33:38 by prichugh          #+#    #+#             */
/*   Updated: 2024/08/06 14:33:39 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	create_window(t_data *data)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr, LEN, HEIGHT, "FDF");
	if (!data->win_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free(data);
		return (0);
	}
	return (1);
}

int	create_image(t_data *data)
{
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, LEN, HEIGHT);
	if (!data->img.img_ptr)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free(data);
		return (0);
	}
	data->img.img_pixels_ptr = mlx_get_data_addr(data->img.img_ptr,
			&data->img.bits_per_pixel, &data->img.line_len, &data->img.endian);
	return (1);
}

void	setup_hooks(t_data *data)
{
	mlx_key_hook(data->win_ptr, handle_input, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, cleanup, data);
}
