/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:33:27 by prichugh          #+#    #+#             */
/*   Updated: 2024/08/06 14:33:30 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (!validate_args(argc) || !validate_file(argv[1]))
		return (0);
	data = init_data(argv[1]);
	if (!data)
		return (1);
	if (!create_window(data) || !create_image(data))
		return (1);
	read_file(argv[1], data);
	center_data(data);
	draw(data);
	setup_hooks(data);
	mlx_loop(data->mlx_ptr);
	cleanup(data);
	return (0);
}
