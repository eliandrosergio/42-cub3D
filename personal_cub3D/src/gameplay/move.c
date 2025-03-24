/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:32:07 by efaustin          #+#    #+#             */
/*   Updated: 2025/03/20 22:10:59 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_valid_move(t_game *game, double x, double y)
{
	double	collision_buffer;

	collision_buffer = 0.1;
	if (x < 0 || y < 0 || x >= game->map.width || y >= game->map.height)
		return (0);
	return (game->map.grid[(int)(y + collision_buffer)][(int)x] != '1'
		&& game->map.grid[(int)(y - collision_buffer)][(int)x] != '1'
		&& game->map.grid[(int)y][(int)(x + collision_buffer)] != '1'
		&& game->map.grid[(int)y][(int)(x - collision_buffer)] != '1');
}

static void	rotate(t_player *player, double speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	player->dir_x = player->dir_x * cos(speed)
		- player->dir_y * sin(speed);
	player->dir_y = old_dir_x * sin(speed)
		+ player->dir_y * cos(speed);
	player->plane_x = player->plane_x * cos(speed)
		- player->plane_y * sin(speed);
	player->plane_y = old_plane_x * sin(speed)
		+ player->plane_y * cos(speed);
	return ;
}

static void	move(t_game *game, double dir_x, double dir_y)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + dir_x * game->player.move_speed;
	new_y = game->player.pos_y + dir_y * game->player.move_speed;
	if (is_valid_move(game, new_x, new_y))
	{
		game->player.pos_x = new_x;
		game->player.pos_y = new_y;
	}
	return ;
}

void	key_move(t_game *game, double dir_x, double dir_y, char move_type)
{
	if (move_type == 'm')
		move(game, dir_x, dir_y);
	else if (move_type == 'r')
		rotate(&game->player, ((int)dir_y * game->player.rot_speed));
	return ;
}
