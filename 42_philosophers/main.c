/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:21:28 by alibourb          #+#    #+#             */
/*   Updated: 2023/07/29 16:49:01 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_platon(t_data *data)
{
	if (data->forks)
		free(data->forks);
	if (data->philo)
		free(data->philo);
}

void	free_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_of_philos)
		pthread_mutex_destroy(&data->forks[i]);
	pthread_mutex_destroy(&data->death_lock);
	pthread_mutex_destroy(&data->meal_lock);
	pthread_mutex_destroy(&data->print_lock);
}

int	main(int ac, char **ag)
{
	t_data	data;

	if ((valid_arguments(ac, ag) != SUCCESS))
		return (write(2, "Invalid arguments\n", 18), 1);
	if (initialize(&data, ag))
	{
		process(&data);
		free_mutex(&data);
		free_platon(&data);
	}
	return (0);
}
