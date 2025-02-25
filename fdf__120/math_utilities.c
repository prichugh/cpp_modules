/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:33:42 by prichugh          #+#    #+#             */
/*   Updated: 2024/08/06 18:33:13 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	max(int x, int y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

int	abs_val(int i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

void	calculate_wireframe_center(t_data *data)
{
	float	min_x;
	float	max_x;
	float	min_y;
	float	max_y;

	min_x = 0;
	max_x = (data->width - 1) * data->scale;
	min_y = 0;
	max_y = (data->height - 1) * data->scale;
	data->transform.center_x = ((min_x + max_x) / 2.0f);
	data->transform.center_y = ((min_y + max_y) / 2.0f);
}
