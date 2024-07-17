/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:47:24 by jarthaud          #+#    #+#             */
/*   Updated: 2023/11/15 14:31:33 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/cub3d.h>

void	ray_throw(t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->ray_dir_x = ray->dir_x + \
		ray->plane_x * ray->camera_x;
	ray->ray_dir_y = ray->dir_y + \
		ray->plane_y * ray->camera_x;
	ray->map_x = (int)ray->pos_x;
	ray->map_y = (int)ray->pos_y;
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = INT_MAX;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = INT_MAX;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

void	step_side_dist(t_ray *ray)
{
	ray->hit = 0;
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (ray->pos_x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - ray->pos_x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (ray->pos_y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - ray->pos_y)
			* ray->delta_dist_y;
	}
}

void	perform_dda(t_ray *ray, t_data *data)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_x < 0.25 || ray->map_y < 0.25
			|| data->map_char[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->side_dist_x
				- ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y
				- ray->delta_dist_y);
}

void	prep_drawing(t_ray *ray)
{
	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
	if (ray->side == 0 && ray->ray_dir_x < 0)
		ray->tex_img = 4;
	else if (ray->side == 0 && ray->ray_dir_x > 0)
		ray->tex_img = 3;
	else if (ray->side == 1 && ray->ray_dir_y < 0)
		ray->tex_img = 2;
	else if (ray->side == 1 && ray->ray_dir_y > 0)
		ray->tex_img = 1;
}

void	calc_texture(t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_x = ray->pos_y + (ray->perp_wall_dist * ray->ray_dir_y);
	else
		ray->wall_x = ray->pos_x + (ray->perp_wall_dist * ray->ray_dir_x);
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (ray->wall_x * TEX_WIDTH);
	if ((ray->side == 0 && ray->ray_dir_x > 0)
		|| (ray->side == 1 && ray->ray_dir_y < 0))
		ray->tex_x = TEX_WIDTH - ray->tex_x - 1;
	ray->step_tex = TEX_HEIGHT * 1.0 / ray->line_height;
	ray->tex_pos = (ray->draw_start - (WIN_HEIGHT / 2) \
			+ (ray->line_height / 2)) * ray->step_tex;
}
