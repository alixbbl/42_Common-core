/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:46:40 by jarthaud          #+#    #+#             */
/*   Updated: 2023/11/08 13:46:41 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/cub3d.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pixel;

	if (y < 0 || y > WIN_HEIGHT - 1 || x < 0 || x > WIN_WIDTH - 1)
		return ;
	pixel = (data->img[0].addr + (y * data->img[0].line_len + x * \
		(data->img[0].bpp / 8)));
	*(int *)pixel = color;
}

void	draw_verti(t_data *data, int x)
{
	int	y;

	y = 0;
	calc_texture(data->ray);
	while (y < data->ray->draw_start)
		my_mlx_pixel_put(data, x, y++, get_int_color(data->rgb_ceiling));
	while (y < data->ray->draw_end)
	{
		my_mlx_pixel_put(data, x, y, get_tex_color(data, data->ray->tex_x,
				(int)data->ray->tex_pos, data->ray->tex_img));
		data->ray->tex_pos += data->ray->step_tex;
		y++;
	}
	while (y < WIN_HEIGHT)
		my_mlx_pixel_put(data, x, y++, get_int_color(data->rgb_floor));
}

int	render(t_data *data)
{	
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		ray_throw(data->ray, x);
		step_side_dist(data->ray);
		perform_dda(data->ray, data);
		prep_drawing(data->ray);
		draw_verti(data, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img[0].img_ptr, 0, 0);
	return (0);
}
