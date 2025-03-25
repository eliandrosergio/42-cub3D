/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:43:19 by efaustin          #+#    #+#             */
/*   Updated: 2025/03/25 10:43:20 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_wall_collision(t_game *game, double x, double y)
{
	double	buffer;

	buffer = 0.2;
	if (x < 0 || y < 0 || x >= game->map.width || y >= game->map.height)
		return (1);
	if (game->map.grid[(int)(y + buffer)][(int)x] == '1'
		|| game->map.grid[(int)(y - buffer)][(int)x] == '1'
		|| game->map.grid[(int)y][(int)(x + buffer)] == '1'
		|| game->map.grid[(int)y][(int)(x - buffer)] == '1')
		return (1);
	return (0);
}

static int	is_sprite_solid(t_game *game, int x, int y)
{
	int	j;

	j = 0;
	while (j < game->spray.spcount)
	{
		if ((int)game->g_sprites[j].x == x && (int)game->g_sprites[j].y == y)
		{
			if (game->g_sprites[j].solid == 1)
				return (1);
			break ;
		}
		j++;
	}
	return (0);
}

static int	check_sprites(t_game *game, int points[4][2])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->map.grid[points[i][0]][points[i][1]] >= '1')
		{
			if (is_sprite_solid(game, points[i][1], points[i][0]))
				return (1);
		}
		i++;
	}
	return (0);
}

int	is_valid_move(t_game *game, double x, double y)
{
	int	points[4][2];

	points[0][0] = (int)(y + 0.2);
	points[0][1] = (int)x;
	points[1][0] = (int)(y - 0.2);
	points[1][1] = (int)x;
	points[2][0] = (int)y;
	points[2][1] = (int)(x + 0.2);
	points[3][0] = (int)y;
	points[3][1] = (int)(x - 0.2);
	if (is_wall_collision(game, x, y))
		return (0);
	if (check_sprites(game, points))
		return (0);
	return (1);
}
