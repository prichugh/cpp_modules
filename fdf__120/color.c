/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:33:47 by prichugh          #+#    #+#             */
/*   Updated: 2024/08/06 14:33:48 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_color(int z1, int z2, t_data *data)
{
	if (z1 < -20 || z2 < -20)
		data->color = 0x005b96;
	else if (z1 < 0 || z2 < 0)
		data->color = 0x4da6ff;
	else if (z1 < 10 || z2 < 10)
		data->color = 0x56ab2f;
	else if (z1 < 30 || z2 < 30)
		data->color = 0xa67c52;
	else if (z1 < 100 || z2 < 100)
		data->color = 0xc0c0c0;
	else
		data->color = 0xffffff;
}
