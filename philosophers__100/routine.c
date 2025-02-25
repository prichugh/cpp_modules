/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:00:39 by prichugh          #+#    #+#             */
/*   Updated: 2024/08/29 14:00:39 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	handle_single_philosopher(t_data *data)
{
	t_philosophers	*philosophers;

	philosophers = data->philosophers;
	philosophers[0].thread_id = 1;
	philosophers[0].data = data;
	philosophers[0].left_fork = 0;
	philosophers[0].meals_eaten = 0;
	philosophers[0].last_meal_time = get_current_time();
	if (pthread_create(&(philosophers[0].thread_pointer),
			NULL, one_philosopher_routine, &(philosophers[0])))
		return (1);
	end_simulation(philosophers);
	return (0);
}

void	*one_philosopher_routine(void *void_philosopher)
{
	t_philosophers	*philosopher;
	t_data			*data;

	philosopher = (t_philosophers *)void_philosopher;
	data = philosopher->data;
	pthread_mutex_lock(&(data->forks[philosopher[0].left_fork]));
	print_status(data, philosopher, "has taken a fork");
	pthread_mutex_unlock(&(data->forks[philosopher[0].left_fork]));
	usleep(data->time_to_die * 1000);
	print_status(data, philosopher, "died");
	return (NULL);
}

void	*routine(void *void_philosophers)
{
	t_philosophers	*philosophers;
	t_data			*data;

	philosophers = (t_philosophers *)void_philosophers;
	data = philosophers->data;
	if ((philosophers->thread_id - 1) % 2)
		usleep(20000);
	while (1)
	{
		pthread_mutex_lock(&(data->death));
		if (data->died)
		{
			pthread_mutex_unlock(&(data->death));
			break ;
		}
		pthread_mutex_unlock(&(data->death));
		ft_eat(philosophers);
		print_status(data, philosophers, "is sleeping");
		ft_sleep(data, data->time_to_sleep);
		print_status(data, philosophers, "is thinking");
		usleep(100);
	}
	return (NULL);
}

void	waiter(t_data *data)
{
	int			i;

	while (!data->died)
	{
		i = 0;
		while (!data->died && i < data->num_of_philosophers)
		{
			pthread_mutex_lock(&(data->eating));
			if (elapsed_time(data->philosophers[i].last_meal_time,
					get_current_time()) >= data->time_to_die)
				update_death_status(data, &data->philosophers[i]);
			pthread_mutex_unlock(&(data->eating));
			usleep(50);
			i++;
		}
		pthread_mutex_lock(&(data->death));
		if (data->died)
		{
			pthread_mutex_unlock(&(data->death));
			break ;
		}
		pthread_mutex_unlock(&(data->death));
		check_all_philosophers_fed(data);
	}
}
