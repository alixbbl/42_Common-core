/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:47:20 by jarthaud          #+#    #+#             */
/*   Updated: 2023/11/15 14:26:25 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/cub3d.h>

int	player_inside(t_data *data)
{
	int	x;
	int	y;

	x = data->ray->pos_x;
	y = data->ray->pos_y;
	if ((x == 0) || (y == 0) || (y == len_tab(data->map_char) - 1)
		|| (is_nothing(data->map_char[y - 1][x]))
	|| (is_nothing(data->map_char[y + 1][x]))
	|| (is_nothing(data->map_char[y][x - 1]))
	|| (is_nothing(data->map_char[y][x + 1]))
	|| (is_nothing(data->map_char[y + 1][x + 1]))
	|| (is_nothing(data->map_char[y + 1][x - 1]))
	|| (is_nothing(data->map_char[y - 1][x + 1]))
	|| (is_nothing(data->map_char[y - 1][x - 1])))
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}

int	check_closed_map(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (data->map_char[++y])
	{
		x = -1;
		while (data->map_char[y][++x])
		{
			if (data->map_char[y][x] == '0')
			{
				if ((x == 0) || (y == 0) || (y == len_tab(data->map_char) - 1)
					|| (is_nothing(data->map_char[y - 1][x]))
				|| (is_nothing(data->map_char[y + 1][x]))
				|| (is_nothing(data->map_char[y][x - 1]))
				|| (is_nothing(data->map_char[y][x + 1]))
				|| (is_nothing(data->map_char[y + 1][x + 1]))
				|| (is_nothing(data->map_char[y + 1][x - 1]))
				|| (is_nothing(data->map_char[y - 1][x + 1]))
				|| (is_nothing(data->map_char[y - 1][x - 1])))
					return (EXIT_FAILURE);
			}
		}
	}
	return (EXIT_SUCCESS);
}

int	check_elements_map(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (data->map_char[++y])
	{
		x = -1;
		while (data->map_char[y][++x])
		{
			if ((data->map_char[y][x] != 'N')
				&& (data->map_char[y][x] != 'S')
				&& (data->map_char[y][x] != 'E')
				&& (data->map_char[y][x] != 'W')
				&& (data->map_char[y][x] != '1')
				&& (data->map_char[y][x] != '0')
				&& (data->map_char[y][x] != '\n')
				&& (data->map_char[y][x] != ' '))
				return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	count_map_elements(t_data *data)
{
	int	x;
	int	y;
	int	player;

	player = 0;
	y = -1;
	while (data->map_char[++y])
	{
		x = -1;
		while (data->map_char[y][++x])
		{
			if ((data->map_char[y][x] == 'N')
				|| (data->map_char[y][x] == 'S')
				|| (data->map_char[y][x] == 'E')
				|| (data->map_char[y][x] == 'W'))
				player++;
		}
	}
	if ((player != 1))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	parsing(t_data *data)
{
	if (check_empty_line(data))
		return (ft_error("---MAP HAS EMPTY LINE---\n"), EXIT_FAILURE);
	if (check_elements_map(data))
		return (ft_error("---WRONG MAP---\n"), EXIT_FAILURE);
	if (check_closed_map(data))
		return (ft_error("---MAP IS NOT CLOSED---\n"), EXIT_FAILURE);
	if (count_map_elements(data))
		return (ft_error("---WRONG NUMBER OF PLAYERS---\n"), EXIT_FAILURE);
	if (parsing_textures(data))
		return (ft_error("---ERROR IN TEXTURES---\n"), EXIT_FAILURE);
	if (parsing_colors(data))
		return (ft_error("---ERROR IN COLORS---\n"), EXIT_FAILURE);
	if (player_inside(data))
		return (ft_error("---PLAYER OUTSIDE THE MAP---\n"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
