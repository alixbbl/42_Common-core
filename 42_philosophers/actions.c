/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:06:32 by alibourb          #+#    #+#             */
/*   Updated: 2023/07/29 16:47:23 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* on prend les forks selon l'ID du philo */
void	forks_please(t_philo *philos)
{
	if (!(philos->id % 2))
	{
		pthread_mutex_lock(&philos->data->forks[philos->left_fork_id]);
		print_activity(philos, "has taken a fork");
		pthread_mutex_lock(&philos->data->forks[philos->right_fork_id]);
		print_activity(philos, "has taken a fork");
	}
	else if (philos->id % 2)
	{
		pthread_mutex_lock(&philos->data->forks[philos->right_fork_id]);
		print_activity(philos, "has taken a fork");
		pthread_mutex_lock(&philos->data->forks[philos->left_fork_id]);
		print_activity(philos, "has taken a fork");
	}
}

/* idem pour reposer les fourchettes, attention a respecter l'ordre pour
eviter un deadlock, notamment si le nombre de philos est eleve */
void	forks_done(t_philo *philos)
{
	if (!(philos->id % 2))
	{
		pthread_mutex_unlock(&philos->data->forks[philos->right_fork_id]);
		pthread_mutex_unlock(&philos->data->forks[philos->left_fork_id]);
	}
	else if (philos->id % 2)
	{
		pthread_mutex_unlock(&philos->data->forks[philos->left_fork_id]);
		pthread_mutex_unlock(&philos->data->forks[philos->right_fork_id]);
	}
}

/* on lance le eating en appelant forks_please, proteger les donnees */
void	philo_is_eating(t_philo *philos)
{
	forks_please(philos);
	print_activity(philos, "is eating");
	pthread_mutex_lock(&philos->data->death_lock);
	philos->last_meal = what_time();
	pthread_mutex_lock(&philos->data->meal_lock);
	philos->nbr_of_meals++;
	pthread_mutex_unlock(&philos->data->meal_lock);
	pthread_mutex_unlock(&philos->data->death_lock);
	ft_usleep(philos->time_to_eat, philos->data);
	forks_done(philos);
}

void	philo_is_sleeping(t_philo *philos)
{
	print_activity(philos, "is sleeping");
	ft_usleep(philos->time_to_sleep, philos->data);
}

void	philo_killing(t_data *data, int i)
{
	pthread_mutex_lock(&data->death_lock);
	data->philo_is_dead = 1;
	pthread_mutex_unlock(&data->death_lock);
	pthread_mutex_lock(&data->print_lock);
	printf("%lld %d died\n", what_time()
		- data->start_time, data->philo[i].id);
	pthread_mutex_unlock(&data->print_lock);
}
