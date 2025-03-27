/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elian <elian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:49:28 by efaustin          #+#    #+#             */
/*   Updated: 2025/03/26 14:30:39 by elian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_game(t_game *game)
{
	cleanup_exit(game, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (init_data(&game))
		cleanup_exit(&game, 1);
	if (check_args(ac, av, &game))
		cleanup_exit(&game, 1);
	if (init_game(&game))
		cleanup_exit(&game, 1);
	start_game(&game);
	mlx_loop(game.mlx);
	cleanup_exit(&game, 0);
	return (0);
}
