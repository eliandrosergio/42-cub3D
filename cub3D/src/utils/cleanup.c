/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:49:10 by efaustin          #+#    #+#             */
/*   Updated: 2025/03/12 12:49:12 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	cleanup_grid(t_game *game)
{
	int		i;

	i = 0;
	if (game->map.grid)
	{
		while (i < game->map.height)
		{
			if (game->map.grid[i])
				free(game->map.grid[i]);
			i++;
		}
		free(game->map.grid);
	}
	game->map.grid = NULL;
	return ;
}

static void	cleanup_path(t_game *game)
{
	if (game->map.path_file)
		free(game->map.path_file);
	game->map.path_file = NULL;
	if (game->textures.east.path)
		free(game->textures.east.path);
	game->textures.east.path = NULL;
	if (game->textures.north.path)
		free(game->textures.north.path);
	game->textures.north.path = NULL;
	if (game->textures.south.path)
		free(game->textures.south.path);
	game->textures.south.path = NULL;
	if (game->textures.west.path)
		free(game->textures.west.path);
	game->textures.west.path = NULL;
	return ;
}

static void	cleanup_img(t_game *game)
{
	if (game->textures.east.img)
		mlx_destroy_image(game->mlx, game->textures.east.img);
	game->textures.east.img = NULL;
	if (game->textures.north.img)
		mlx_destroy_image(game->mlx, game->textures.north.img);
	game->textures.north.img = NULL;
	if (game->textures.west.img)
		mlx_destroy_image(game->mlx, game->textures.west.img);
	game->textures.west.img = NULL;
	if (game->textures.south.img)
		mlx_destroy_image(game->mlx, game->textures.south.img);
	game->textures.south.img = NULL;
	if (game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	game->img.img = NULL;
	return ;
}

void	cleanup_exit(t_game *game, int exitcode)
{
	cleanup_grid(game);
	cleanup_path(game);
	cleanup_img(game);
	get_next_line(0, 1);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(exitcode);
	return ;
}

int	exit_game(t_game *game)
{
	cleanup_exit(game, 0);
	return (0);
}
