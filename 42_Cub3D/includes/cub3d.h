/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:12:25 by jarthaud          #+#    #+#             */
/*   Updated: 2023/11/10 09:53:41 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdbool.h>
# include <limits.h>

# define WIN_WIDTH 980
# define WIN_HEIGHT 640
# define TEX_WIDTH 100
# define TEX_HEIGHT 100
# define ROTSPEED 0.06
# define MOVESPEED 0.06

typedef struct s_ray {
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	ray_dir_x;
	double	ray_dir_y;
	double	camera_x;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	old_dir_x;
	double	old_plane_x;
	int		tex_img;
	double	step_tex;
	double	tex_pos;
	int		tex_x;
	double	wall_x;
}				t_ray;

typedef struct s_img {
	void	*img_ptr;
	char	*addr;
	char	*path;
	int		bpp;
	int		line_len;
	int		endian;
	int		height;
	int		width;
}				t_img;

typedef struct s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img[5];
	t_ray	*ray;
	int		player;
	char	**map_char;
	int		empty_line;
	int		line_map;
	int		index_map;
	int		*rgb_ceiling;
	int		*rgb_floor;
	int		flag_pars;
}				t_data;

/********** HOOKS ***********/
int		handle_keypress(int keysym, t_data *data);
int		handle_buttonpress(t_data *data);
void	move_side(t_data *data, int flag);
void	move_front(t_data *data, int flag);
void	rotate(t_data *data, int flag);

/************************ INIT *************************/
int		save_data(char *infile, t_data *data);
int		init_data(t_data *data);
int		init_player_pos(char *str, int y, t_data *data);
void	init_ray_cast(t_ray *ray);
int		check_args(int ac, char **av);
void	init_pos_ns(t_data *data, int flag, int i, int y);
void	init_pos_ew(t_data *data, int flag, int i, int y);

/************************  MAP  *************************/
int		fill_colors(char *str, t_data *data);
int		fill_text(char *str, t_data *data);
int		text_colors_filled(t_data *data);
int		colors_filled(t_data *data);
int		text_filled(t_data *data);
int		fill_map(char *str, t_data *data, int i);
int		save_map(char *infile, t_data *data);

/************************PARSING*************************/
int		parsing(t_data *data);
int		parsing_textures(t_data *data);
int		count_map_elements(t_data *data);
int		check_elements_map(t_data *data);
int		check_closed_map(t_data *data);
int		empty_line(char *str);
int		check_empty_line(t_data *data);
int		parsing_colors(t_data *data);
int		player_inside(t_data *data);

/***********************  UTILS  ************************/
int		len_tab(char **tab);
int		is_nothing(char c);
bool	test_path_texture(char *code_texture);
int		ft_isspace(int c);

/******************** ERRORS / FREE *********************/
void	ft_error(char *message);
void	free_tabs(char **tab);
void	free_all(t_data *data);
void	free_all2(t_data *data);
void	close_all(t_data *data);

/********** DRAW ***********/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_verti(t_data *data, int x);
int		get_tex_color(t_data *data, int x, int y, int i);
int		get_int_color(int rgb[3]);
int		render(t_data *data);

/********** RAY_CAST ***********/
void	ray_throw(t_ray *ray, int x);
void	step_side_dist(t_ray *ray);
void	prep_drawing(t_ray *ray);
void	perform_dda(t_ray *ray, t_data *data);
void	calc_texture(t_ray *ray);
int		text_init(t_data *data, int i);
int		game_init(t_data *data);
int		game_loop(t_data *data);

#endif
