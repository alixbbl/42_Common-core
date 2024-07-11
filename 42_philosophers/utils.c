/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:25:11 by alibourb          #+#    #+#             */
/*   Updated: 2023/07/07 15:31:20 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_activity(t_philo *philos, char *str)
{
	if (philo_is_dead(philos->data) || everybody_is_full(philos->data))
		return ;
	pthread_mutex_lock(&philos->data->print_lock);
	printf("%lld %d %s\n", what_time()
		- philos->data->start_time, philos->id, str);
	pthread_mutex_unlock(&philos->data->print_lock);
}

long long	what_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(long long time_ms, t_data *data)
{
	long long	time;

	time = what_time();
	while ((what_time() - time < time_ms) && !philo_is_dead(data)
		&& !everybody_is_full(data))
		usleep(1000);
}
