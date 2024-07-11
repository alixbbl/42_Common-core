/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:25:55 by alibourb          #+#    #+#             */
/*   Updated: 2023/07/29 16:47:39 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* on externalise la fonction pour une meilleure gestion des mutex */
long long	get_last_meal(t_philo *philo)
{
	long long	check_last_meal;

	pthread_mutex_lock(&philo->data->death_lock);
	check_last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->data->death_lock);
	return (check_last_meal);
}

/* mini-monitoring relatif a la variable mandatory_meals */
int	everybody_is_full(t_data *data)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	if (data->philo->mandatory_meals == -1)
		return (0);
	pthread_mutex_lock(&data->meal_lock);
	while (++i < data->nbr_of_philos)
	{
		if (data->philo[i].nbr_of_meals >= data->philo->mandatory_meals)
			count ++;
	}
	pthread_mutex_unlock(&data->meal_lock);
	return (count == data->nbr_of_philos);
}

/* fonction de base pour verifier si la variable de la struct data */
int	philo_is_dead(t_data *data)
{
	pthread_mutex_lock(&data->death_lock);
	if (data->philo_is_dead == 1)
	{
		pthread_mutex_unlock(&data->death_lock);
		return (1);
	}
	pthread_mutex_unlock(&data->death_lock);
	return (0);
}

/* on break dans le monitoring, qui inclue le nbr de repas max et le passage de
la variable philo a 1 si le time_to_die depasse le temps impose */
void	monitoring(t_data *data)
{
	int	i;

	while (!data->philo_is_dead)
	{
		i = -1;
		while (++i < data->nbr_of_philos)
		{
			if (what_time() - get_last_meal(&data->philo[i])
				>= data->time_to_die)
			{
				philo_killing(data, i);
				break ;
			}
			if (everybody_is_full(data))
				break ;
			ft_usleep(1, data);
		}
		if (everybody_is_full(data))
			break ;
	}
}
