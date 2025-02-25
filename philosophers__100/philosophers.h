/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:49:25 by prichugh          #+#    #+#             */
/*   Updated: 2024/09/09 12:49:25 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philosophers
{
	int				thread_id;
	pthread_t		thread_pointer;
	struct s_data	*data;
	int				left_fork;
	int				right_fork;
	long long		last_meal_time;
	int				meals_eaten;
}				t_philosophers;

typedef struct s_waiter
{
	pthread_t		waiter_pointer;
	struct s_data	*data;
}					t_waiter;

typedef struct s_data
{
	int				num_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_meals;
	long long		zero_time;
	t_philosophers	philosophers[200];
	pthread_mutex_t	forks[200];
	pthread_mutex_t	eating;
	pthread_mutex_t	printing;
	pthread_mutex_t	death;
	pthread_mutex_t	meals_eaten;
	int				died;
	t_waiter		waiter;
}					t_data;

/*
** ----- init_data.c -----
*/

void		init_data(int argc, char **argv);

/*
** ----- main.c -----
*/

int			ft_isdigit(int c);
int			is_number(char *argv);
int			is_valid_argc(int argc);
int			is_valid_argv(char **argv);

/*
** ----- time.c -----
*/
size_t		get_current_time(void);
long long	elapsed_time(long long start, long long end);

/*
** ----- routine.c -----
*/
void		*one_philosopher_routine(void *void_philosopher);
int			handle_single_philosopher(t_data *data);
void		*routine(void *void_philosophers);
void		waiter(t_data *data);

/*
** ----- action.c -----
*/
void		ft_sleep(t_data *data, long long time);
void		ft_eat(t_philosophers *philosopher);

/*
** ----- utils.c -----
*/
int			end_simulation(t_philosophers *philosophers);
void		print_status(t_data *data, t_philosophers *philosopher, char *str);
int			ft_atoi(const char *str);
void		check_all_philosophers_fed(t_data *data);
void		update_death_status(t_data *data, t_philosophers *philosopher);

#endif
