/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling_and_floor.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:44:37 by efaustin          #+#    #+#             */
/*   Updated: 2025/03/24 15:44:39 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_floorcast(t_floorcast *fc, t_game *game, int y)
{
	fc->y = y;
	fc->ray_dir_x0 = game->player.dir_x - game->player.plane_x;
	fc->ray_dir_y0 = game->player.dir_y - game->player.plane_y;
	fc->ray_dir_x1 = game->player.dir_x + game->player.plane_x;
	fc->ray_dir_y1 = game->player.dir_y + game->player.plane_y;
	fc->row_distance = (0.5 * HEIGHT) / (fc->y - HEIGHT / 2);
	fc->floor_step_x = fc->row_distance
		* (fc->ray_dir_x1 - fc->ray_dir_x0) / WIDTH;
	fc->floor_step_y = fc->row_distance
		* (fc->ray_dir_y1 - fc->ray_dir_y0) / WIDTH;
	fc->floor_x = game->player.pos_x + fc->row_distance * fc->ray_dir_x0;
	fc->floor_y = game->player.pos_y + fc->row_distance * fc->ray_dir_y0;
}

static void	process_floor_row(t_game *game, t_floorcast *fc)
{
	t_img	*floor_tex;
	t_img	*ceiling_tex;

	fc->x = 0;
	floor_tex = &game->textures.floor;
	ceiling_tex = &game->textures.ceiling;
	while (fc->x < WIDTH)
	{
		fc->cell_x = (int)fc->floor_x;
		fc->cell_y = (int)fc->floor_y;
		fc->tex_x = (int)(TEXWIDTH *(fc->floor_x - fc->cell_x))
			& (TEXWIDTH - 1);
		fc->tex_y = (int)(TEXHEIGHT * (fc->floor_y - fc->cell_y))
			& (TEXHEIGHT - 1);
		my_mlx_pixel_put(&game->img, fc->x, fc->y,
			get_pixel_color(floor_tex, fc->tex_x, fc->tex_y));
		my_mlx_pixel_put(&game->img, fc->x, HEIGHT - fc->y - 1,
			get_pixel_color(ceiling_tex, fc->tex_x, fc->tex_y));
		fc->floor_x += fc->floor_step_x;
		fc->floor_y += fc->floor_step_y;
		fc->x++;
	}
}

void	draw_ceiling_and_floor(t_game *game)
{
	t_floorcast	fc;

	fc.y = HEIGHT / 2;
	while (fc.y < HEIGHT)
	{
		init_floorcast(&fc, game, fc.y);
		process_floor_row(game, &fc);
		fc.y++;
	}
}
