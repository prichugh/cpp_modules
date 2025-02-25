/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:33:32 by prichugh          #+#    #+#             */
/*   Updated: 2024/08/06 15:55:51 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	validate_args(int argc)
{
	if (argc < 2)
	{
		ft_printf("Too few parameters.\n");
		ft_printf("Enter args as follows: ./fdf  *.fdf\n");
		return (0);
	}
	else if (argc > 2)
	{
		ft_printf("Too many parameters.\n");
		ft_printf("Enter args as follows: ./fdf  *.fdf\n");
		return (0);
	}
	return (1);
}

int	validate_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0 || read(fd, 0, 0) < 0)
	{
		ft_printf("Invalid file name or no reading rights.\n");
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
