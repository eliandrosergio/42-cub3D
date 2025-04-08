/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:27:55 by efaustin          #+#    #+#             */
/*   Updated: 2025/04/03 13:41:21 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <string.h>

# define WIDTH 1280
# define HEIGHT 720
# define TITLE "github.com/eliandrosergio/cub3D"

# define TEXWIDTH 1024
# define TEXHEIGHT 1024
# define NUM_SPRITES 3
# define MAX_SPRITES 64
# define SPEED_PLAYER 0.08
# define SPEED_CAMERA 0.04

# define KEY_ESQ 65307
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_LSHIFT 65505

typedef struct s_sprite
{
	double		x;
	double		y;
	int			id;
	int			solid;
	double		distance;
}	t_sprite;

typedef struct s_spdata
{
	double		dist1;
	double		dist2;
	double		sprite_x;
	double		sprite_y;
	double		transform_x;
	double		transform_y;
	int			spcount;
	int			sprite_screen_x;
	int			sprite_height;
	int			sprite_width;
	int			draw_start_x;
	int			draw_end_x;
	int			draw_start_y;
	int			draw_end_y;
	t_sprite	sprites[MAX_SPRITES];
}	t_spdata;

typedef struct t_floorcast
{
	int			x;
	int			y;
	int			cell_x;
	int			cell_y;
	int			tex_x;
	int			tex_y;
	double		ray_dir_x0;
	double		ray_dir_y0;
	double		ray_dir_x1;
	double		ray_dir_y1;
	double		row_distance;
	double		floor_x;
	double		floor_y;
	double		floor_step_x;
	double		floor_step_y;
}	t_floorcast;

typedef struct s_wall
{
	double		step;
	double		tex_pos;
	int			tex_x;
	int			draw_end;
	int			draw_start;
	int			line_height;
}	t_wall;

typedef struct s_move
{
	int			speed;
	char		move_v;
	char		move_h;
	char		camera;
}	t_move;

typedef struct s_img
{
	void		*img;
	char		*addr;
	char		*path;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_img;

typedef struct s_texture
{
	t_img		east;
	t_img		north;
	t_img		south;
	t_img		west;
	t_img		floor;
	t_img		ceiling;
	t_img		sprites[NUM_SPRITES];
}	t_texture;

typedef struct s_ray
{
	double		dir_x;
	double		dir_y;
	double		wall_x;
	double		side_dist_y;
	double		side_dist_x;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	double		wall_distances[WIDTH];
	int			map_y;
	int			map_x;
	int			step_x;
	int			step_y;
	int			side;
}	t_ray;

typedef struct s_player
{
	int			dir;
	float		speed;
	double		pos_y;
	double		pos_x;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}	t_player;

typedef struct s_map
{
	int			width;
	int			height;
	int			height_file;
	char		*path_file;
	char		**grid;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_ray		ray;
	t_map		map;
	t_move		move;
	t_player	player;
	t_texture	textures;
	t_spdata	spdata;
}	t_game;

// check
int		check_file(char *file);
int		check_map_lines(char *line);
int		chekc_map_grid(t_game *game);
int		get_end_line(t_game *game, int y);
int		get_start_line(t_game *game, int y);
int		check_extension(char *str, char *key);
int		check_param_lines(t_game *game, char *line);
int		check_args(int ac, char **av, t_game *game);
int		check_map_chars(t_game *game, char *line, int y);
int		border_erro(char *str1, int x, char *str2, int y);

// gameplay
void	start_game(t_game *game);
int		mouse_move(int x, int y, t_game *game);
int		is_valid_move(t_game *game, double x, double y);
void	key_move(t_game *game, double dir_x, double dir_y, char move_type);

// init
int		init_data(t_game *game);
int		init_game(t_game *game);
int		init_sprites(t_game *game);
void	sort_sprites(t_game *game, int i);

// parser
int		get_line_file(t_game *game);
int		save_file_info(t_game *game);
char	*trim_spaces(char *line, char *srch);
char	**allocate_grid(int width, int height);
int		fill_map(t_game *game, char *line, int *fd, int *i);

// render
void	sprites(t_game *game);
void	raycasting(t_game *game);
void	draw_ray(t_game *game, int x);
void	draw_ceiling_and_floor(t_game *game);
int		get_pixel_color(t_img *img, int x, int y);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

// utils
int		is_num(char *str);
void	print_erro(char *str);
int		exit_game(t_game *game);
int		is_only_spaces(char *line);
void	cleanup_exit(t_game *game, int exitcode);
int		return_erro(char *str1, char *str2, char *str3, char *line);

#endif
