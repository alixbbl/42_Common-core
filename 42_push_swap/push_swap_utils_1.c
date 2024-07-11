/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:24:54 by alibourb          #+#    #+#             */
/*   Updated: 2023/02/16 17:10:26 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_putstr_print(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (1);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] && fd > 0)
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	ft_putendl_fd(char *s, int fd)
{
	{
		ft_putstr_fd(s, fd);
		write(fd, "\n", 1);
	}
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
