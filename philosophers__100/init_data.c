/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:49:22 by prichugh          #+#    #+#             */
/*   Updated: 2024/09/09 12:49:22 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_philosophers(t_data *data)
{
	t_philosophers	*philosophers;
	int				i;

	i = 0;
	philosophers = data->philosophers;
	while (i < data->num_of_philosophers)
	{
		philosophers[i].thread_id = i + 1;
		philosophers[i].data = data;
		philosophers[i].left_fork = i;
		philosophers[i].right_fork = (i + 1) % data->num_of_philosophers;
		philosophers[i].meals_eaten = 0;
		philosophers[i].last_meal_time = get_current_time();
		if (pthread_create(&(philosophers[i].thread_pointer),
				NULL, routine, &(philosophers[i])))
			return (1);
		i++;
	}
	waiter(data);
	end_simulation(philosophers);
	return (0);
}

int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philosophers)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL) != 0)
			return (1);
		i++;
	}
	if (pthread_mutex_init(&(data->eating), NULL) != 0)
		return (1);
	if (pthread_mutex_init(&(data->printing), NULL) != 0)
		return (1);
	if (pthread_mutex_init(&(data->death), NULL) != 0)
		return (1);
	if (pthread_mutex_init(&(data->meals_eaten), NULL) != 0)
		return (1);
	return (0);
}

void	parse_arguments(t_data *data, int argc, char **argv)
{
	data->num_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->number_of_meals = ft_atoi(argv[5]);
	else
		data->number_of_meals = -1;
}

int	initialize_simulation(t_data *data)
{
	data->zero_time = get_current_time();
	data->died = 0;
	if (init_mutex(data) != 0)
	{
		printf("[error]\nFailed to initialize mutexes\n");
		return (1);
	}
	if (data->num_of_philosophers == 1)
	{
		handle_single_philosopher(data);
		return (1);
	}
	if (init_philosophers(data) != 0)
	{
		printf("[error]\nFailed to initialize philosophers\n");
		return (1);
	}
	return (0);
}

void	init_data(int argc, char **argv)
{
	t_data	data;

	parse_arguments(&data, argc, argv);
	if (initialize_simulation(&data) != 0)
		return ;
}
