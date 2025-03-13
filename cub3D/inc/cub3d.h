/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:49:38 by efaustin          #+#    #+#             */
/*   Updated: 2025/03/12 15:20:24 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <string.h>

# define WIDTH 800
# define HEIGHT 640
# define TITLE "cub3D"
# define TEXWIDTH 64
# define TEXHEIGHT 64

# define KEY_ESQ 65307
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

typedef struct s_img
{
	void		*img;
	char		*addr;
	char		*path;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_img;

typedef struct s_ray
{
	double		dir_x;
	double		dir_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	double		wall_x;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			side;
	int			tex_num;
}	t_ray;

typedef struct s_map
{
	int			width;
	int			height;
	int			floor;
	int			ceiling;
	int			height_file;
	char		*path_file;
	char		**grid;
}	t_map;

typedef struct s_move
{
	int			move_v;
	int			move_h;
	int			camera;
}	t_move;

typedef struct s_player
{
	int			dir;
	double		pos_y;
	double		pos_x;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rot_speed;
}	t_player;

typedef struct s_texture
{
	t_img		east;
	t_img		north;
	t_img		south;
	t_img		west;
}	t_texture;

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

// gameplay
void	start_game(t_game *game);

// init
int		init_data(t_game *game);
int		init_game(t_game *game);
char	**allocate_grid(int width, int height);
int		load_texture(t_game *game, char tex_dir);

// parser
int		get_line_file(t_game *game);
int		save_file_info(t_game *game);
char	*trim_spaces(char *line, char *srch);
int		fill_map(t_game *game, char *line, int *fd, int *i);

// utils
int		is_num(char val);
void	print_erro(char *str);
int		rgb_to_hex(char *line);
int		exit_game(t_game *game);
int		check_colorcode(char *line);
int		ft_strchr_int(const char *s, int c);
void	cleanup_exit(t_game *game, int exitcode);
int		return_erro(char *str1, char *str2, char *str3, char *line);

#endif
