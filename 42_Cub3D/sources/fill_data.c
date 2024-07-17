/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:46:02 by jarthaud          #+#    #+#             */
/*   Updated: 2023/11/15 14:31:46 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/cub3d.h>

int	fill_map(char *str, t_data *data, int i)
{
	if (i == 0)
	{
		data->map_char = malloc(sizeof(char *) * (data->line_map + 1));
		if (!data->map_char)
			return (EXIT_FAILURE);
	}
	data->map_char[i] = ft_strdup(str);
	if (!data->map_char[i])
		return (EXIT_FAILURE);
	if (init_player_pos(data->map_char[i], i, data))
		return (EXIT_FAILURE);
	if (i == (data->line_map - 1))
		data->map_char[i + 1] = NULL;
	return (EXIT_SUCCESS);
}

int	fill_cf_colors(int flag, int i, t_data *data, char *tmp)
{
	int	j;

	j = 0;
	while (tmp && ft_isspace(*tmp))
		tmp++;
	while (tmp[j] && tmp[j] != '\n')
	{
		if (ft_isdigit(tmp[j]))
			return (1);
		j++;
	}
	if (flag)
		data->rgb_floor[i] = ft_atoi(tmp);
	else
		data->rgb_ceiling[i] = ft_atoi(tmp);
	return (0);
}

int	fill_colors(char *str, t_data *data)
{
	char	**tmp;
	int		i;
	int		flag;

	flag = 0;
	if (str[0] == 'F')
		flag = 1;
	str++;
	while (ft_isspace(*str))
		str++;
	tmp = ft_split(str, ',');
	if (!tmp || (len_tab(tmp) != 3))
		return (free_tabs(tmp), 1);
	i = -1;
	while (++i < 3)
	{
		if (fill_cf_colors(flag, i, data, tmp[i]))
			return (free_tabs(tmp), 1);
	}
	if (flag)
		data->rgb_floor[3] = 1;
	else
		data->rgb_ceiling[3] = 1;
	return (free_tabs(tmp), EXIT_SUCCESS);
}

int	fill_text(char *str, t_data *data)
{
	int	flag;

	flag = 0;
	if (!ft_strncmp(str, "NO", 2))
		flag = 1;
	else if (!ft_strncmp(str, "SO", 2))
		flag = 2;
	else if (!ft_strncmp(str, "WE", 2))
		flag = 3;
	else if (!ft_strncmp(str, "EA", 2))
		flag = 4;
	str = str + 2;
	while (*str && ft_isspace(*str))
		str++;
	if (flag == 1)
		data->img[1].path = ft_strdup_trim(str);
	else if (flag == 2)
		data->img[2].path = ft_strdup_trim(str);
	else if (flag == 3)
		data->img[3].path = ft_strdup_trim(str);
	else if (flag == 4)
		data->img[4].path = ft_strdup_trim(str);
	return (EXIT_SUCCESS);
}
