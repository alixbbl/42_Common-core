/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:47:00 by jarthaud          #+#    #+#             */
/*   Updated: 2023/11/15 14:30:46 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/cub3d.h>

int	init_data(t_data *data)
{
	int	i;

	data->line_map = 0;
	data->index_map = 0;
	data->player = 0;
	data->flag_pars = 0;
	data->map_char = NULL;
	data->rgb_ceiling = ft_calloc(4, sizeof(int));
	if (!data->rgb_ceiling)
		return (EXIT_FAILURE);
	data->rgb_floor = ft_calloc(4, sizeof(int));
	if (!data->rgb_floor)
		return (EXIT_FAILURE);
	data->ray = malloc(sizeof(t_ray) * 1);
	if (!data->ray)
		return (EXIT_FAILURE);
	init_ray_cast(data->ray);
	i = 0;
	while (i < 5)
	{
		data->img[i].path = NULL;
		data->img[i].addr = NULL;
		i++;
	}
	return (EXIT_SUCCESS);
}

void	init_pos_ns(t_data *data, int flag, int i, int y)
{
	data->ray->pos_x = i + 0.5;
	data->ray->pos_y = y + 0.5;
	if (flag)
	{
		data->ray->dir_x = 0;
		data->ray->dir_y = -1;
		data->ray->plane_x = 0.66;
		data->ray->plane_y = 0;
	}
	else if (!flag)
	{
		data->ray->dir_x = 0;
		data->ray->dir_y = 1;
		data->ray->plane_x = -0.66;
		data->ray->plane_y = 0;
	}
}

void	init_pos_ew(t_data *data, int flag, int i, int y)
{
	data->ray->pos_x = i + 0.5;
	data->ray->pos_y = y + 0.5;
	if (flag)
	{
		data->ray->dir_x = 1.00;
		data->ray->dir_y = 0;
		data->ray->plane_x = 0;
		data->ray->plane_y = 0.66;
	}
	else if (!flag)
	{
		data->ray->dir_x = -1;
		data->ray->dir_y = 0;
		data->ray->plane_x = 0;
		data->ray->plane_y = -0.66;
	}
}

int	init_player_pos(char *str, int y, t_data *data)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if ((str[i] == 'N' || str[i] == 'W' || str[i] == 'E'
				|| str[i] == 'S') && !data->player)
		{
			if (str[i] == 'N')
				init_pos_ns(data, 1, i, y);
			else if (str[i] == 'S')
				init_pos_ns(data, 0, i, y);
			else if (str[i] == 'E')
				init_pos_ew(data, 1, i, y);
			else if (str[i] == 'W')
				init_pos_ew(data, 0, i, y);
			data->player++;
			return (EXIT_SUCCESS);
		}
		else if ((str[i] == 'N' || str[i] == 'W' || str[i] == 'E'
				|| str[i] == 'S') && data->player)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	init_ray_cast(t_ray *ray)
{
	ray->ray_dir_x = 0;
	ray->ray_dir_y = 0;
	ray->camera_x = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->side_dist_x = 0;
	ray->side_dist_y = 0;
	ray->delta_dist_x = 0;
	ray->delta_dist_y = 0;
	ray->step_x = 0;
	ray->hit = 0;
	ray->side = 0;
	ray->perp_wall_dist = 0;
	ray->line_height = 0;
	ray->draw_end = 0;
	ray->draw_start = 0;
	ray->old_dir_x = 0;
	ray->old_plane_x = 0;
	ray->tex_img = 0;
	ray->step_tex = 0;
	ray->tex_pos = 0;
	ray->tex_x = 0;
	ray->wall_x = 0;
}
