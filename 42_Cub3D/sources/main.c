/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:47:06 by jarthaud          #+#    #+#             */
/*   Updated: 2023/11/15 14:31:07 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/cub3d.h>

int	check_args(int ac, char **av)
{
	int	i;

	if (ac != 2)
		return (ft_error("--BAD NUMBER OF ARGUMENTS--\n"), EXIT_FAILURE);
	if ((access(av[1], F_OK)) || (access(av[1], R_OK)))
		return (ft_error("---MAP NOT FOUND---\n"), EXIT_FAILURE);
	i = 0;
	while (av[1][i] != '.' && av[1][i])
		i++;
	if (av[1][i + 1] == 'c' && av[1][i + 2] == 'u'
		&& av[1][i + 3] == 'b' && av[1][i + 4] == '\0')
		return (EXIT_SUCCESS);
	else
		return (ft_error("---WRONG TYPE OF MAP---\n"), EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (check_args(ac, av))
		return (EXIT_FAILURE);
	if (init_data(&data))
		return (free_all(&data), EXIT_FAILURE);
	if (save_data(av[1], &data))
		return (free_all2(&data), EXIT_FAILURE);
	if (save_map(av[1], &data))
		return (free_all2(&data), EXIT_FAILURE);
	if (parsing(&data))
		return (free_all(&data), EXIT_FAILURE);
	if (game_init(&data))
		return (free_all(&data), EXIT_FAILURE);
	game_loop(&data);
	return (EXIT_SUCCESS);
}
