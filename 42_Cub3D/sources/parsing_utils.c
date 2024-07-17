/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:47:13 by jarthaud          #+#    #+#             */
/*   Updated: 2023/11/15 14:27:53 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/cub3d.h>

void	ft_error(char *message)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
}

int	empty_line(char *str)
{
	int	i;

	i = 0;
	if (!str[i] || str[i] == '\n')
		return (EXIT_FAILURE);
	while (str[i] && str[i] != '\n')
	{
		if ((str[i] != ' ') && (str[i] != '\t'))
			return (EXIT_SUCCESS);
		i++;
	}
	return (EXIT_FAILURE);
}

int	check_empty_line(t_data *data)
{
	int	y;

	y = 0;
	if (!data->map_char)
		return (EXIT_FAILURE);
	while (data->map_char[y])
	{
		if (empty_line(data->map_char[y]))
			return (EXIT_FAILURE);
		y++;
	}
	return (EXIT_SUCCESS);
}

int	is_nothing(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || !c)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

bool	test_path_texture(char *path_texture)
{
	char	*path;
	int		i;

	if (!path_texture || !*path_texture)
		return (false);
	i = 0;
	while (path_texture[i])
		i++;
	path = malloc(sizeof(char) * (i + 1));
	if (!path)
		return (false);
	i = 0;
	while (path_texture[i])
	{
		path[i] = path_texture[i];
		i++;
	}
	path[i] = '\0';
	if ((access(path, F_OK) == -1) || (access(path, R_OK) == -1))
		return (free(path), false);
	else
		return (free(path), true);
}
