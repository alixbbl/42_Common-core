/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:46:48 by jarthaud          #+#    #+#             */
/*   Updated: 2023/11/08 16:50:17 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/cub3d.h>

int	text_init(t_data *data, int i)
{
	while (++i < 5)
	{
		if (i == 0)
		{
			data->img[i].img_ptr = mlx_new_image(data->mlx_ptr,
					WIN_WIDTH, WIN_HEIGHT);
			if (!data->img[i].img_ptr)
				return (free(data->mlx_ptr), EXIT_FAILURE);
		}
		else
		{
			data->img[i].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
					data->img[i].path, &data->img[i].width,
					&data->img[i].height);
			if (!data->img[i].img_ptr)
				return (close_all(data), EXIT_FAILURE);
		}
		data->img[i].addr = mlx_get_data_addr(data->img[i].img_ptr,
				&data->img[i].bpp, &data->img[i].line_len,
				&data->img[i].endian);
	}
	return (EXIT_SUCCESS);
}

int	game_init(t_data *data)
{
	int	i;

	i = -1;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (ft_error("---MLX FAILED YOU BABE---\n"), EXIT_FAILURE);
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!data->win_ptr)
		return (free(data->mlx_ptr),
			ft_error("---MLX FAILED YOU BABE---\n"), EXIT_FAILURE);
	if (text_init(data, i))
		return (close_all(data),
			ft_error("---MLX FAILED YOU BABE---\n"), EXIT_FAILURE);
	return (0);
}

int	game_loop(t_data *data)
{
	render(data);
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, handle_keypress, data);
	mlx_hook(data->win_ptr, 17, 0, handle_buttonpress, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
