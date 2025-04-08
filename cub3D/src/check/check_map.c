/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:47:54 by efaustin          #+#    #+#             */
/*   Updated: 2025/04/03 11:28:50 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	define_player_help(t_game *game, char dir)
{
	if (dir == 'S')
	{
		game->player.dir_x = 0.0;
		game->player.dir_y = 1.0;
		game->player.plane_x = 0.66;
		game->player.plane_y = 0.0;
	}
	else if (dir == 'E')
	{
		game->player.dir_x = 1.0;
		game->player.dir_y = 0.0;
		game->player.plane_x = 0.0;
		game->player.plane_y = -0.66;
	}
	else if (dir == 'W')
	{
		game->player.dir_x = -1.0;
		game->player.dir_y = 0.0;
		game->player.plane_x = 0.0;
		game->player.plane_y = 0.66;
	}
	return ;
}

static int	define_player_position(t_game *game, int y, int x, char dir)
{
	if (game->player.dir)
		return (return_erro("Só é permitido um indicador de posição (N,S,W,E)"
				" no mapa\n", 0, 0, 0));
	if (dir == 'N')
	{
		game->player.dir_x = 0.0;
		game->player.dir_y = -1.0;
		game->player.plane_x = -0.66;
		game->player.plane_y = 0.0;
	}
	else
		define_player_help(game, dir);
	game->player.pos_y = (double)(y + 0.5);
	game->player.pos_x = (double)(x + 0.5);
	game->map.grid[y][x] = dir;
	game->player.dir = 1;
	return (0);
}

int	check_map_chars(t_game *game, char *line, int y)
{
	int		x;

	x = 0;
	while (line[x])
	{
		if (line[x] == 'N' || line[x] == 'S'
			|| line[x] == 'E' || line[x] == 'W')
		{
			if (define_player_position(game, y, x, line[x]))
				return (1);
		}
		else if (line[x] == '1' || line[x] == '0')
			game->map.grid[y][x] = line[x];
		else if (line[x] == ' ')
			game->map.grid[y][x] = 'V';
		else if (line[x] != '\n')
			return (return_erro("Caractere inválido no mapa\n", 0, 0, 0));
		x++;
	}
	while (x < game->map.width)
		game->map.grid[y][x++] = 'V';
	game->map.grid[y][x] = '\0';
	return (0);
}

int	check_map_lines(char *line)
{
	int		status;
	char	*temp;

	status = 0;
	temp = ft_strdup(line);
	if (!temp)
		return (return_erro("Falha ao alocar memória do mapa\n", 0, 0, 0));
	line = trim_spaces(temp, " ");
	if (line && (line[0] == '\0' || line[0] == '\n'))
		status = 0;
	else if (line && line[0] == '1')
		status = 2;
	else
		status = return_erro("Caractere inválido ao ler o mapa\n", 0, 0, 0);
	free(line);
	return (status);
}
