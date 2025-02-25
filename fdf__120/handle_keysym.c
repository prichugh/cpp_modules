/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keysym.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:33:20 by prichugh          #+#    #+#             */
/*   Updated: 2024/08/06 14:35:58 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_exit(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		cleanup(data);
}

void	handle_reset(int keysym, t_data *data)
{
	if (keysym == XK_r)
		reset_data(data);
}

void	handle_movement(int keysym, t_data *data)
{
	if (keysym == XK_Left)
		data->shift_x -= 10;
	if (keysym == XK_Right)
		data->shift_x += 10;
	if (keysym == XK_Up)
		data->shift_y -= 10;
	if (keysym == XK_Down)
		data->shift_y += 10;
	if (keysym == XK_equal && data->scale < MAX_SCALE)
		adjust_scale(data, 1.1);
	if (keysym == XK_minus && data->scale > MIN_SCALE)
		adjust_scale(data, 0.9);
}

void	handle_rotation(int keysym, t_data *data)
{
	if (keysym == XK_w)
		data->transform.angle_x += 0.1f;
	if (keysym == XK_s)
		data->transform.angle_x -= 0.1f;
	if (keysym == XK_a)
		data->transform.angle_y -= 0.1f;
	if (keysym == XK_d)
		data->transform.angle_y += 0.1f;
	if (keysym == XK_q)
		data->transform.angle_z -= 0.1f;
	if (keysym == XK_e)
		data->transform.angle_z += 0.1f;
}

int	handle_input(int keysym, t_data *data)
{
	handle_exit(keysym, data);
	handle_movement(keysym, data);
	handle_rotation(keysym, data);
	handle_help_menu(keysym, data);
	handle_reset(keysym, data);
	redraw_image(data);
	return (0);
}
