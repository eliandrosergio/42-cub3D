/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:48:16 by efaustin          #+#    #+#             */
/*   Updated: 2025/03/12 15:20:24 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_mlx(t_game *game)
{
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, TITLE);
	if (!game->win)
	{
		perror("Erro ao Inicializar a Janela MLX\n");
		return (1);
	}
	game->img.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img.img)
	{
		perror("Erro ao criar a Imagem MLX\n");
		return (1);
	}
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
			&game->img.line_length, &game->img.endian);
	return (0);
}

static int	init_assets(t_game *game)
{
	if (load_texture(game, 'E') || load_texture(game, 'N')
		|| load_texture(game, 'W') || load_texture(game, 'S'))
	{
		perror("Erro ao carregar as texturas\n");
		return (1);
	}
	return (0);
}

int	init_game(t_game *game)
{
	game->player.move_speed = 0.08;
	game->player.rot_speed = 0.06;
	if (init_assets(game) == 1)
		return (1);
	if (init_mlx(game) == 1)
		return (1);
	return (0);
}

int	init_data(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		print_erro("Erro ao inicializar o MLX\n");
		return (1);
	}
	return (0);
}
