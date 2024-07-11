/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:45:06 by alibourb          #+#    #+#             */
/*   Updated: 2023/07/29 16:46:10 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define TRUE 			1
# define SUCCESS		1
# define FALSE			0
# define ERROR			0
# define FAILURE		0
# define NBR_PHILOS_MAX 201
# define INT_MAX		2147483647
# define INT_MIN		-2147483648
# define DEAD			0

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdint.h>
# include <time.h>

typedef struct s_philo
{
	int				id;
	int				left_fork_id;
	int				right_fork_id;
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	int				nbr_of_meals;
	int				mandatory_meals;
	long int		last_meal;
	pthread_t		thread_id;
	struct s_data	*data;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

typedef struct s_data
{
	int				nbr_of_philos;
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	int				meals_completed;
	int				mandatory_meals;
	long int		start_time;
	int				philo_is_dead;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	*forks;
	t_philo			*philo;
}	t_data;

/* CHECK_ARGS */
int			rights_nbr_of_args(int ac);
int			arg_is_number(int ac, char **ag);
int			right_nbr_of_philos(char **ag);
int			valid_time_args(int ac, char **ag);
int			valid_arguments(int ac, char **ag);

/* INITIALIZATION */
int			philos_init(t_data *data);
int			mutex_init(t_data *data);
int			simul_init(t_data	*data, char **ag);
int			initialize(t_data *data, char **ag);

/* ROUTINE & ACTIONS */
int			process(t_data *data);
int			philo_is_dead(t_data *data);
void		philo_killing(t_data *data, int i);
void		*philo_routine(void *args);
void		one_philo(t_data *data);
void		forks_please(t_philo *philos);
void		forks_done(t_philo *philos);
void		philo_is_eating(t_philo *philos);
void		philo_is_sleeping(t_philo *philos);

/* MONITORING */
int			everybody_is_full(t_data *data);
long long	get_last_meal(t_philo *philo);
void		monitoring(t_data *data);

/* UTILS */
int			check_numb(char *argv);
int			check_int(char *argv);
int			ft_nbrlen(char *numb);
int			ft_atoi(char *str);
long		ft_atol(char *str);
void		print_activity(t_philo *philos, char *message);
long long	what_time(void);
void		ft_usleep(long long time_ms, t_data *data);
void		free_platon(t_data *data);
void		free_mutex(t_data *data);

#endif
