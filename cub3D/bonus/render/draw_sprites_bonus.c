/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:43:28 by efaustin          #+#    #+#             */
/*   Updated: 2025/03/26 15:19:30 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	transform_sprite_helper(t_game *game)
{
	game->spdata.sprite_width = game->spdata.sprite_height;
	game->spdata.draw_start_y = -(game->spdata.sprite_height) / 2 + HEIGHT / 2;
	if (game->spdata.draw_start_y < 0)
		game->spdata.draw_start_y = 0;
	game->spdata.draw_end_y = (game->spdata.sprite_height) / 2 + HEIGHT / 2;
	if (game->spdata.draw_end_y >= HEIGHT)
		game->spdata.draw_end_y = HEIGHT - 1;
	game->spdata.draw_start_x = -(game->spdata.sprite_width) / 2
		+ game->spdata.sprite_screen_x;
	if (game->spdata.draw_start_x < 0)
		game->spdata.draw_start_x = 0;
	game->spdata.draw_end_x = (game->spdata.sprite_width) / 2
		+ game->spdata.sprite_screen_x;
	if (game->spdata.draw_end_x >= WIDTH)
		game->spdata.draw_end_x = WIDTH - 1;
	return ;
}

static void	transform_sprite(t_game *game, int i)
{
	double	inv_det;

	game->spdata.sprite_x = game->spdata.sprites[i].x - game->player.pos_x;
	game->spdata.sprite_y = game->spdata.sprites[i].y - game->player.pos_y;
	inv_det = 1.0 / (game->player.plane_x * game->player.dir_y
			- game->player.dir_x * game->player.plane_y);
	game->spdata.transform_x = inv_det * (game->player.dir_y
			* game->spdata.sprite_x - game->player.dir_x
			* game->spdata.sprite_y);
	game->spdata.transform_y = inv_det * (-game->player.plane_y
			* game->spdata.sprite_x + game->player.plane_x
			* game->spdata.sprite_y);
	game->spdata.sprite_screen_x = (int)((WIDTH / 2) * (1
				+ game->spdata.transform_x / game->spdata.transform_y));
	game->spdata.sprite_height = abs((int)(HEIGHT
				/ game->spdata.transform_y));
	transform_sprite_helper(game);
	return ;
}

static void	draw_sp_helper(t_game *game, int i, int tex_x, int stripe)
{
	int		y;
	int		d;
	int		color;
	int		tex_y;
	t_img	*texture;

	y = game->spdata.draw_start_y;
	while (y < game->spdata.draw_end_y)
	{
		d = y * 256 - HEIGHT * 128 + game->spdata.sprite_height * 128;
		tex_y = ((d * TEXHEIGHT) / game->spdata.sprite_height) / 256;
		texture = &game->textures.sprites[(game->spdata.sprites[i].id) - 2];
		color = get_pixel_color(texture, tex_x, tex_y);
		if ((color & 0x00FFFFFF) != 0)
			my_mlx_pixel_put(&game->img, stripe, y, color);
		y++;
	}
	return ;
}

void	draw_sp(t_game *game, int i)
{
	int		tex_x;
	int		stripe;
	double	sprite_depth;

	tex_x = 0;
	transform_sprite(game, i);
	stripe = game->spdata.draw_start_x;
	sprite_depth = game->spdata.transform_y;
	while (stripe < game->spdata.draw_end_x)
	{
		tex_x = (int)(256 * (stripe - (-game->spdata.sprite_width / 2
						+ game->spdata.sprite_screen_x))
				* TEXWIDTH / game->spdata.sprite_width) / 256;
		if (sprite_depth > 0 && stripe > 0 && stripe < WIDTH)
			if (sprite_depth < game->ray.wall_distances[stripe])
				draw_sp_helper(game, i, tex_x, stripe);
		stripe++;
	}
	return ;
}

void	sprites(t_game *game)
{
	int		i;

	sort_sprites(game, -1);
	i = 0;
	while (i < game->spdata.spcount)
	{
		draw_sp(game, i);
		i++;
	}
	return ;
}
