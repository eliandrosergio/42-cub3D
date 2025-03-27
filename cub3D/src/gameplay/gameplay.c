/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:27:55 by efaustin          #+#    #+#             */
/*   Updated: 2025/03/26 14:00:09 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	key_press(int key, t_game *game)
{
	if (key == KEY_ESQ)
		exit_game(game);
	if (key == KEY_W)
		game->move.move_v = 'w';
	if (key == KEY_S)
		game->move.move_v = 's';
	if (key == KEY_A)
		game->move.move_h = 'a';
	if (key == KEY_D)
		game->move.move_h = 'd';
	if (key == KEY_LEFT)
		game->move.camera = 'l';
	if (key == KEY_RIGHT)
		game->move.camera = 'r';
	return (0);
}

static int	key_release(int key, t_game *game)
{
	if (key == KEY_ESQ)
		exit_game(game);
	if (key == KEY_ESQ)
		exit_game(game);
	if (key == KEY_W)
		game->move.move_v = ' ';
	if (key == KEY_S)
		game->move.move_v = ' ';
	if (key == KEY_A)
		game->move.move_h = ' ';
	if (key == KEY_D)
		game->move.move_h = ' ';
	if (key == KEY_LEFT)
		game->move.camera = ' ';
	if (key == KEY_RIGHT)
		game->move.camera = ' ';
	return (0);
}

static int	movement_player(t_game *game)
{
	if (game->move.move_v == 'w')
		key_move(game, game->player.dir_x, game->player.dir_y, 'm');
	else if (game->move.move_v == 's')
		key_move(game, -game->player.dir_x, -game->player.dir_y, 'm');
	if (game->move.move_h == 'a')
		key_move(game, -game->player.plane_x, -game->player.plane_y, 'm');
	else if (game->move.move_h == 'd')
		key_move(game, game->player.plane_x, game->player.plane_y, 'm');
	if (game->move.camera == 'l')
		key_move(game, 0, 1, 'r');
	else if (game->move.camera == 'r')
		key_move(game, 0, -1, 'r');
	return (0);
}

static int	gameplay(t_game *game)
{
	movement_player(game);
	draw_ceiling_and_floor(game);
	raycasting(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}

void	start_game(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 17, 1L << 17, exit_game, game);
	mlx_loop_hook(game->mlx, gameplay, game);
}
