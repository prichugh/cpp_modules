/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:05:28 by prichugh          #+#    #+#             */
/*   Updated: 2024/08/29 14:05:28 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_all_philosophers_fed(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(data->meals_eaten));
	if (data->number_of_meals == -1)
	{
		pthread_mutex_unlock(&(data->meals_eaten));
		return ;
	}
	while (i < data->num_of_philosophers)
	{
		if (data->philosophers[i].meals_eaten < data->number_of_meals)
		{
			pthread_mutex_unlock(&(data->meals_eaten));
			return ;
		}
		i++;
	}
	pthread_mutex_unlock(&(data->meals_eaten));
	pthread_mutex_lock(&(data->death));
	data->died = 1;
	pthread_mutex_unlock(&(data->death));
}

void	print_status(t_data *data, t_philosophers *philosopher, char *str)
{
	long long	i;
	long long	j;

	i = get_current_time();
	j = data->zero_time;
	pthread_mutex_lock(&(data->printing));
	pthread_mutex_lock(&(data->death));
	if (!data->died)
		printf("%lli %i %s\n", elapsed_time(j, i), philosopher->thread_id, str);
	pthread_mutex_unlock(&(data->death));
	pthread_mutex_unlock(&(data->printing));
}

void	update_death_status(t_data *data, t_philosophers *philosopher)
{
	print_status(data, philosopher, "died");
	pthread_mutex_lock(&(data->death));
	data->died = 1;
	pthread_mutex_unlock(&(data->death));
}

int	end_simulation(t_philosophers *philosophers)
{
	int		i;
	t_data	*data;

	data = philosophers->data;
	i = 0;
	while (i < data->num_of_philosophers)
	{
		if (pthread_join(philosophers[i].thread_pointer, NULL))
			return (1);
		i++;
	}
	i = 0;
	while (i < data->num_of_philosophers)
	{
		pthread_mutex_destroy(&(data->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(data->eating));
	pthread_mutex_destroy(&(data->printing));
	pthread_mutex_destroy(&(data->meals_eaten));
	pthread_mutex_destroy(&(data->death));
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		neg;
	long	res;

	i = 0;
	neg = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	return (res * neg);
}
