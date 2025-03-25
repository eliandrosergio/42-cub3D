/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:43:28 by efaustin          #+#    #+#             */
/*   Updated: 2025/03/25 10:43:29 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	sort_sprites(t_game *game, int i)
{
	int			j;
	t_sprite	temp;

	j = -1;
	temp = game->g_sprites[j];
	while (++i < game->spray.spcount - 1)
	{
		j = -1;
		while (++j < game->spray.spcount - i - 1)
		{
			game->spray.dist1 = pow(game->g_sprites[j].x
					- game->player.pos_x, 2) + pow(game->g_sprites[j].y
					- game->player.pos_y, 2);
			game->spray.dist2 = pow(game->g_sprites[j + 1].x
					- game->player.pos_x, 2) + pow(game->g_sprites[j + 1].y
					- game->player.pos_y, 2);
			if (game->spray.dist1 < game->spray.dist2)
			{
				temp = game->g_sprites[j];
				game->g_sprites[j] = game->g_sprites[j + 1];
				game->g_sprites[j + 1] = temp;
			}
		}
	}
	return ;
}

static void	transform_sprite(t_game *game)
{
	game->spray.sprite_width = game->spray.sprite_height;
	game->spray.draw_start_y = -(game->spray.sprite_height) / 2 + HEIGHT / 2;
	if (game->spray.draw_start_y < 0)
		game->spray.draw_start_y = 0;
	game->spray.draw_end_y = (game->spray.sprite_height) / 2 + HEIGHT / 2;
	if (game->spray.draw_end_y >= HEIGHT)
		game->spray.draw_end_y = HEIGHT - 1;
	game->spray.draw_start_x = -(game->spray.sprite_width) / 2
		+ game->spray.sprite_screen_x;
	if (game->spray.draw_start_x < 0)
		game->spray.draw_start_x = 0;
	game->spray.draw_end_x = (game->spray.sprite_width) / 2
		+ game->spray.sprite_screen_x;
	if (game->spray.draw_end_x >= WIDTH)
		game->spray.draw_end_x = WIDTH - 1;
	return ;
}

static void	render_sprite_helper(t_game *game, int i, int tex_x, int stripe)
{
	int		y;
	int		d;
	int		color;
	int		tex_y;
	t_img	*texture;

	texture = &game->textures.sprite2;
	y = game->spray.draw_start_y;
	while (y < game->spray.draw_end_y)
	{
		texture = &game->textures.sprite2;
		d = y * 256 - HEIGHT * 128 + game->spray.sprite_height * 128;
		tex_y = ((d * TEXHEIGHT) / game->spray.sprite_height) / 256;
		if (game->g_sprites[i].id == 3)
			texture = &game->textures.sprite3;
		if (game->g_sprites[i].id == 4)
			texture = &game->textures.sprite4;
		color = get_pixel_color(texture, tex_x, tex_y);
		if ((color & 0x00FFFFFF) != 0)
			my_mlx_pixel_put(&game->img, stripe, y, color);
		y++;
	}
	return ;
}

static void	render_sprite(t_game *game, int i)
{
	int		tex_x;
	int		stripe;

	tex_x = 0;
	transform_sprite(game);
	stripe = game->spray.draw_start_x;
	while (stripe < game->spray.draw_end_x)
	{
		tex_x = (int)(256 * (stripe - (-game->spray.sprite_width / 2
						+ game->spray.sprite_screen_x))
				* TEXWIDTH / game->spray.sprite_width) / 256;
		if (game->spray.transform_y > 0 && stripe > 0 && stripe < WIDTH)
			render_sprite_helper(game, i, tex_x, stripe);
		stripe++;
	}
}

void	draw_sprites(t_game *game)
{
	int		i;
	double	inv_det;

	i = -1;
	find_sprites(game);
	sort_sprites(game, -1);
	while (++i < game->spray.spcount)
	{
		game->spray.sprite_x = game->g_sprites[i].x - game->player.pos_x;
		game->spray.sprite_y = game->g_sprites[i].y - game->player.pos_y;
		inv_det = 1.0 / (game->player.plane_x * game->player.dir_y
				- game->player.dir_x * game->player.plane_y);
		game->spray.transform_x = inv_det * (game->player.dir_y
				* game->spray.sprite_x - game->player.dir_x
				* game->spray.sprite_y);
		game->spray.transform_y = inv_det * (-game->player.plane_y
				* game->spray.sprite_x + game->player.plane_x
				* game->spray.sprite_y);
		game->spray.sprite_screen_x = (int)((WIDTH / 2) * (1
					+ game->spray.transform_x / game->spray.transform_y));
		game->spray.sprite_height = abs((int)(HEIGHT
					/ game->spray.transform_y));
		render_sprite(game, i);
	}
}
