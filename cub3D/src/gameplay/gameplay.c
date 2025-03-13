/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:27:55 by efaustin          #+#    #+#             */
/*   Updated: 2025/03/13 14:27:59 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	key_press(int key, t_game *game)
{
	if (key == KEY_ESQ)
		exit_game(game);
	else
		printf("teclou\n");
	return (1);
}

static int	key_release(int key, t_game *game)
{
	if (key == KEY_ESQ)
		exit_game(game);
	else
		printf("teclou\n");
	return (1);
}

void	start_game(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 17, 1L << 17, exit_game, game);
}
