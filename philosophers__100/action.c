/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:03:39 by prichugh          #+#    #+#             */
/*   Updated: 2024/08/29 14:03:39 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	update_meals_eaten(t_philosophers *philosopher)
{
	t_data	*data;

	data = philosopher->data;
	pthread_mutex_lock(&(data->meals_eaten));
	philosopher->meals_eaten += 1;
	pthread_mutex_unlock(&(data->meals_eaten));
}

void	ft_eat(t_philosophers *philosopher)
{
	t_data	*data;

	data = philosopher->data;
	if (philosopher->left_fork < philosopher->right_fork)
	{
		pthread_mutex_lock(&(data->forks[philosopher->left_fork]));
		print_status(data, philosopher, "has taken a fork");
		pthread_mutex_lock(&(data->forks[philosopher->right_fork]));
		print_status(data, philosopher, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&(data->forks[philosopher->right_fork]));
		print_status(data, philosopher, "has taken a fork");
		pthread_mutex_lock(&(data->forks[philosopher->left_fork]));
		print_status(data, philosopher, "has taken a fork");
	}
	pthread_mutex_lock(&(data->eating));
	print_status(data, philosopher, "is eating");
	philosopher->last_meal_time = get_current_time();
	pthread_mutex_unlock(&(data->eating));
	ft_sleep(data, data->time_to_eat);
	pthread_mutex_unlock(&(data->forks[philosopher->left_fork]));
	pthread_mutex_unlock(&(data->forks[philosopher->right_fork]));
	update_meals_eaten(philosopher);
}

void	ft_sleep(t_data *data, long long time)
{
	long long	i;

	i = get_current_time();
	while (1)
	{
		pthread_mutex_lock(&(data->death));
		if (data->died)
		{
			pthread_mutex_unlock(&(data->death));
			break ;
		}
		pthread_mutex_unlock(&(data->death));
		if (elapsed_time(i, get_current_time()) >= time)
			break ;
		usleep(100);
	}
}
