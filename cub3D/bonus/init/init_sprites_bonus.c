/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:48:16 by efaustin          #+#    #+#             */
/*   Updated: 2025/03/26 14:57:02 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	find_sprites_helper(t_game *game, int y, int x)
{
	char	cell;

	cell = game->map.grid[y][x];
	if (cell >= '2' && cell <= '9')
	{
		if (game->spdata.spcount < MAX_SPRITES)
		{
			game->spdata.sprites[game->spdata.spcount].x = x + 0.5;
			game->spdata.sprites[game->spdata.spcount].y = y + 0.5;
			game->spdata.sprites[game->spdata.spcount].id = cell - '0';
			game->spdata.spcount++;
		}
	}
	return ;
}

static void	find_sprites(t_game *game)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
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

static int	load_sprites(t_game *game)
{
	int		i;
	int		width;
	int		height;
	char	path[28];
	t_img	*texture;

	i = -1;
	ft_strlcpy(path, "./assets/sprite/sprite0.xpm", 28);
	while (++i <= 2)
	{
		path[22] = '0' + i;
		if (check_file(path))
			return (return_erro("Não foi possivel localizar um sprite\n"
					, 0, 0, 0));
		texture = &game->textures.sprites[i];
		texture->path = ft_strdup(path);
		texture->img = mlx_xpm_file_to_image(game->mlx, texture->path,
				&width, &height);
		if (!texture->img)
			return (return_erro("Falha ao carregar um sprite\n", 0, 0, 0));
		texture->addr = mlx_get_data_addr(texture->img,
				&texture->bits_per_pixel, &texture->line_length,
				&texture->endian);
	}
	return (0);
}

void	sort_sprites(t_game *game, int i)
{
	int			j;
	int			k;
	t_sprite	temp;

	j = -1;
	k = -1;
	while (++j < game->spdata.spcount)
		game->spdata.sprites[j].distance = pow(game->spdata.sprites[j].x
				- game->player.pos_x, 2) + pow(game->spdata.sprites[j].y
				- game->player.pos_y, 2);
	while (++k < game->spdata.spcount - 1)
	{
		j = -1;
		while (++j < game->spdata.spcount - i - 1)
		{
			if (game->spdata.sprites[j].distance
				< game->spdata.sprites[j + 1].distance)
			{
				temp = game->spdata.sprites[j];
				game->spdata.sprites[j] = game->spdata.sprites[j + 1];
				game->spdata.sprites[j + 1] = temp;
			}
		}
	}
}

int	init_sprites(t_game *game)
{
	if (load_sprites(game))
		return (1);
	find_sprites(game);
	sort_sprites(game, -1);
	return (0);
}
