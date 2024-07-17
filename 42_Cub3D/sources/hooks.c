/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:46:55 by jarthaud          #+#    #+#             */
/*   Updated: 2023/11/10 09:31:55 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/cub3d.h>

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		free_all(data);
		close_all(data);
		exit (0);
	}
	if (keysym == XK_Right)
		rotate(data, 1);
	if (keysym == XK_Left)
		rotate(data, 0);
	if (keysym == XK_w)
		move_front(data, 1);
	if (keysym == XK_s)
		move_front(data, 0);
	if (keysym == XK_d)
		move_side(data, 1);
	if (keysym == XK_a)
		move_side(data, 0);
	return (0);
}

int	handle_buttonpress(t_data *data)
{
	free_all(data);
	close_all(data);
	exit (0);
}

void	rotate(t_data *data, int flag)
{
	data->ray->old_dir_x = data->ray->dir_x;
	data->ray->old_plane_x = data->ray->plane_x;
	if (flag)
	{
		data->ray->dir_x = (data->ray->dir_x * cos(ROTSPEED)) - \
			(data->ray->dir_y * sin(ROTSPEED));
		data->ray->dir_y = (data->ray->old_dir_x * sin(ROTSPEED)) + \
			(data->ray->dir_y * cos(ROTSPEED));
		data->ray->plane_x = (data->ray->plane_x * cos(ROTSPEED)) - \
			(data->ray->plane_y * sin(ROTSPEED));
		data->ray->plane_y = (data->ray->old_plane_x * sin(ROTSPEED)) + \
			(data->ray->plane_y * cos(ROTSPEED));
	}
	if (!flag)
	{
		data->ray->dir_x = (data->ray->dir_x * cos(-ROTSPEED)) - \
			(data->ray->dir_y * sin(-ROTSPEED));
		data->ray->dir_y = (data->ray->old_dir_x * sin(-ROTSPEED)) + \
			(data->ray->dir_y * cos(-ROTSPEED));
		data->ray->plane_x = (data->ray->plane_x * cos(-ROTSPEED)) - \
			(data->ray->plane_y * sin(-ROTSPEED));
		data->ray->plane_y = (data->ray->old_plane_x * sin(-ROTSPEED)) + \
			(data->ray->plane_y * cos(-ROTSPEED));
	}
}

void	move_front(t_data *data, int flag)
{
	if (flag)
	{
		if (data->map_char[(int)(data->ray->pos_y)][(int)(data->ray->pos_x
				+ data->ray->dir_x * MOVESPEED)] != '1')
			data->ray->pos_x += data->ray->dir_x * MOVESPEED;
		if (data->map_char[(int)(data->ray->pos_y + data->ray->dir_y
				* MOVESPEED)][(int)(data->ray->pos_x)] != '1')
			data->ray->pos_y += data->ray->dir_y * MOVESPEED;
	}
	if (!flag)
	{
		if (data->map_char[(int)(data->ray->pos_y)][(int)(data->ray->pos_x
				- data->ray->dir_x * MOVESPEED)] != '1')
			data->ray->pos_x -= data->ray->dir_x * MOVESPEED;
		if (data->map_char[(int)(data->ray->pos_y + data->ray->dir_y
				* MOVESPEED)][(int)(data->ray->pos_x)] != '1')
			data->ray->pos_y -= data->ray->dir_y * MOVESPEED;
	}
}

void	move_side(t_data *data, int flag)
{
	if (flag)
	{
		if (data->map_char[(int)(data->ray->pos_y)][(int)(data->ray->pos_x
				+ data->ray->plane_x * MOVESPEED)] != '1')
			data->ray->pos_x += data->ray->plane_x * MOVESPEED;
		if (data->map_char[(int)(data->ray->pos_y + data->ray->plane_y
				* MOVESPEED)][(int)(data->ray->pos_x)] != '1')
			data->ray->pos_y += data->ray->plane_y * MOVESPEED;
	}
	if (!flag)
	{
		if (data->map_char[(int)(data->ray->pos_y)][(int)(data->ray->pos_x
				- data->ray->plane_x * MOVESPEED)] != '1')
			data->ray->pos_x -= data->ray->plane_x * MOVESPEED;
		if (data->map_char[(int)(data->ray->pos_y + data->ray->plane_y
				* MOVESPEED)][(int)(data->ray->pos_x)] != '1')
			data->ray->pos_y -= data->ray->plane_y * MOVESPEED;
	}
}
