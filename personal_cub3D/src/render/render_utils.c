/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:41:30 by efaustin          #+#    #+#             */
/*   Updated: 2025/03/18 10:41:33 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_pixel_color(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return ;
}

static void	find_sprites_helper(t_game *game, int y, int x)
{
	char	cell;

	cell = game->map.grid[y][x];
	if (cell == '2' || cell == '3' || cell == '4')
	{
		if (game->spray.spcount < MAX_SPRITES)
		{
			game->g_sprites[game->spray.spcount].x = x + 0.5;
			game->g_sprites[game->spray.spcount].y = y + 0.5;
			game->g_sprites[game->spray.spcount].id = cell - '0';
			game->g_sprites[game->spray.spcount].solid = 0;
			if (cell != '2')
				game->g_sprites[game->spray.spcount].solid = 1;
			game->spray.spcount++;
		}
	}
	return ;
}

void	find_sprites(t_game *game)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	game->spray.spcount = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			find_sprites_helper(game, y, x);
			x++;
		}
		y++;
	}
	return ;
}
