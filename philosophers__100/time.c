/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:43:16 by prichugh          #+#    #+#             */
/*   Updated: 2024/08/26 12:43:16 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("[ERROR]\n gettimeofday() failed\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

long long	elapsed_time(long long start, long long end)
{
	return (end - start);
}
