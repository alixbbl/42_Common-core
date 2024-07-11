/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:50:30 by alibourb          #+#    #+#             */
/*   Updated: 2023/07/29 16:51:04 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_routine(void *args)
{
	t_philo	*philos;

	philos = (t_philo *)args;
	print_activity(philos, "is thinking");
	if (!(philos->id % 2))
		ft_usleep(philos->time_to_eat / 2, philos->data);
	while ((!philo_is_dead(philos->data)) && !everybody_is_full(philos->data))
	{
		philo_is_eating(philos);
		philo_is_sleeping(philos);
		print_activity(philos, "is thinking");
		usleep(2000);
	}
	return (NULL);
}

/* Fonction appelee dans le main si un seul philo */
void	one_philo(t_data *data)
{
	print_activity(data->philo, "has taken a fork");
	usleep(data->time_to_die / 2);
	print_activity(data->philo, "died");
}

/* Fonction pour lancer les threads, le monitoring et le join des threads */
int	process(t_data *data)
{
	int	i;

	i = -1;
	data->start_time = what_time();
	if (data->nbr_of_philos == 1)
	{
		one_philo(data);
		return (0);
	}
	while (++i < data->nbr_of_philos)
	{
		if (pthread_create(&data->philo[i].thread_id, NULL, &philo_routine,
				&data->philo[i]))
			return (1);
	}
	monitoring(data);
	i = -1;
	while (++i < data->nbr_of_philos)
		pthread_join(data->philo[i].thread_id, NULL);
	return (SUCCESS);
}
