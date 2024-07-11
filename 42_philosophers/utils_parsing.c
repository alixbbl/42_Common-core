/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:44:13 by alibourb          #+#    #+#             */
/*   Updated: 2023/07/05 16:42:51 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		result;
	char	*cstr;

	i = 0;
	sign = 1;
	result = 0;
	cstr = (char *)str;
	while (((cstr[i] <= 13 && cstr[i] >= 9)) || cstr[i] == ' ')
		i++;
	if (cstr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (cstr[i] == '+')
		i++;
	while ((cstr[i] >= '0' && cstr[i] <= '9') && cstr[i])
	{
		result *= 10;
		result = result + (cstr[i] - '0');
		i++;
	}
	return (sign * result);
}

long	ft_atol(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (((str[i] <= 13 && str[i] >= 9))
		|| (str[i] == ' ') || str[i] == '0')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result *= 10;
		result = result + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

int	ft_nbrlen(char *numb)
{
	int	len_nbr;
	int	i;

	i = 0;
	len_nbr = 0;
	if (!numb)
		return (0);
	while (numb[i] == '0')
		i++;
	if (numb[i] == '+')
		i++;
	else if ((numb[i] == '-') || (numb[i] > '0' && numb[i] <= '9'))
	{
		len_nbr++;
		i++;
	}
	while (numb[i] >= '0' && numb[i] <= '9' )
	{
		len_nbr++;
		i++;
	}
	return (len_nbr);
}

int	check_numb(char *ag)
{
	int	i;

	if (!ag)
		return (0);
	i = 0;
	if (ag[0] == '-' || ag[0] == '+')
	{
		i++;
		if (!(ag[1] >= '0' && ag[i] <= '9'))
			return (0);
	}
	while (ag[i])
	{
		if (ag[i] >= '0' && ag[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_int(char *ag)
{
	int		len_nbr;
	long	numb;

	len_nbr = ft_nbrlen(ag);
	numb = ft_atol(ag);
	if ((len_nbr > 11) || (numb > INT_MAX) || (numb < INT_MIN))
		return (0);
	return (1);
}
