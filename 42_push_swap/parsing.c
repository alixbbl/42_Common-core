/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:51:58 by alibourb          #+#    #+#             */
/*   Updated: 2023/03/10 10:38:52 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_numb(char *argv)
{
	int	i;

	if (!argv)
		return (0);
	i = 0;
	if (argv[0] == '-' || argv[0] == '+')
		i++;
	while (argv[i])
	{
		if (argv[i] >= '0' && argv[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_int(char *argv)
{
	int		len_nbr;
	long	numb;

	len_nbr = ft_nbrlen(argv);
	numb = ft_atol(argv);
	if ((len_nbr > 11) || (numb > INT_MAX) || (numb < INT_MIN))
		return (0);
	return (1);
}

int	check_double(int ac, int *argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac - 1)
	{
		j = i + 1;
		while (j < ac - 1)
		{
			if (argv[i] == argv[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	parsing(int ac, char **argv)
{
	int	i;
	int	j;
	int	*tab_argv;

	tab_argv = malloc(sizeof(int) * (ac - 1));
	if (!tab_argv)
		return (0);
	i = 0;
	while (argv[++i])
	{
		if (!check_numb(argv[i]) || (!check_int(argv[i])))
			return (free (tab_argv), 0);
	}
	i = 0;
	j = -1;
	while (++i < ac)
		tab_argv[++j] = (int)ft_atol(argv[i]);
	if (!check_double(ac, tab_argv))
		return (free (tab_argv), 0);
	free (tab_argv);
	return (1);
}
