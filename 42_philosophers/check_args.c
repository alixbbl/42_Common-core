/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:28:53 by alibourb          #+#    #+#             */
/*   Updated: 2023/07/29 16:48:27 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	rights_nbr_of_args(int ac)
{
	if ((ac < 5) || (ac > 6))
		return (ERROR);
	return (SUCCESS);
}

int	arg_is_number(int ac, char **ag)
{
	int	i;
	int	res;

	i = 1;
	res = 0;
	while (i < ac)
	{
		res = check_numb(ag[i]);
		if (!res)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	right_nbr_of_philos(char **ag)
{
	if ((ft_atoi(ag[1]) < 1) || (ft_atoi(ag[1]) >= NBR_PHILOS_MAX))
		return (ERROR);
	return (SUCCESS);
}

int	valid_time_args(int ac, char **ag)
{
	int	i;
	int	res;

	i = 1;
	while (i < ac)
	{
		res = check_int(ag[i]);
		if (!res || (ft_atol(ag[i]) <= 0))
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	valid_arguments(int ac, char **ag)
{
	if (!(rights_nbr_of_args(ac)))
		return (ERROR);
	if (!(arg_is_number(ac, ag)))
		return (ERROR);
	if (!valid_time_args(ac, ag))
		return (ERROR);
	if (!(right_nbr_of_philos(ag)))
		return (ERROR);
	return (SUCCESS);
}
