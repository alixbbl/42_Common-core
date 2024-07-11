/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:22:44 by alibourb          #+#    #+#             */
/*   Updated: 2023/07/29 15:45:06 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philos_init(t_data *data)
{
	int	i;

	i = -1;
	data->philo = malloc(sizeof(t_philo) * (data->nbr_of_philos));
	if (!data->philo)
		return (free_platon(data), FAILURE);
	while (++i < data->nbr_of_philos)
	{
		data->philo[i].data = data;
		data->philo[i].id = i + 1;
		data->philo[i].time_to_eat = data->time_to_eat;
		data->philo[i].time_to_die = data->time_to_die;
		data->philo[i].time_to_sleep = data->time_to_sleep;
		data->philo[i].thread_id = 0;
		data->philo[i].nbr_of_meals = 0;
		data->philo[i].mandatory_meals = data->mandatory_meals;
		data->philo[i].last_meal = what_time();
		data->philo[i].left_fork_id = i;
		data->philo[i].right_fork_id = (i + 1) % data->nbr_of_philos;
		data->philo[i].left_fork = &data->forks[i];
		data->philo[i].right_fork = &data->forks[(i + 1) % data->nbr_of_philos];
	}
	return (SUCCESS);
}

int	mutex_init(t_data *data)
{
	int	i;

	i = -1;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nbr_of_philos);
	if (!data->forks)
		return (free_platon(data), FAILURE);
	while (++i < data->nbr_of_philos)
		pthread_mutex_init(&data->forks[i], NULL);
	return (SUCCESS);
}

int	simul_init(t_data *data, char **ag)
{
	data->nbr_of_philos = ft_atoi(ag[1]);
	data->time_to_die = ft_atoi(ag[2]);
	data->time_to_eat = ft_atoi(ag[3]);
	data->time_to_sleep = ft_atoi(ag[4]);
	if (ag[5])
		data->mandatory_meals = ft_atoi(ag[5]);
	else if (!ag[5])
		data->mandatory_meals = -1;
	data->meals_completed = 0;
	data->start_time = what_time();
	data->philo_is_dead = 0;
	pthread_mutex_init(&data->death_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
	pthread_mutex_init(&data->print_lock, NULL);
	return (SUCCESS);
}

int	initialize(t_data *data, char **ag)
{
	if (simul_init(data, ag))
		if (mutex_init(data))
			if (philos_init(data))
				return (1);
	return (0);
}
