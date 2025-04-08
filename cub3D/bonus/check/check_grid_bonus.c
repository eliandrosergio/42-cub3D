/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:47:46 by efaustin          #+#    #+#             */
/*   Updated: 2025/04/03 13:49:48 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	check_player_border(t_map *map, int y, int x, int last_line)
{
	if (y != 0)
		if (map->grid[y - 1][x] != '1' && map->grid[y - 1][x] != '0')
			return (border_erro("Borda superior inválida do caractere ",
					x, " da linha ", y));
	if (y != last_line)
		if (map->grid[y + 1][x] != '1' && map->grid[y + 1][x] != '0')
			return (border_erro("Borda inferior inválida do caractere ",
					x, " da linha ", y));
	if ((x - 1) >= 0)
		if (map->grid[y][x - 1] != '1' && map->grid[y][x - 1] != '0')
			return (border_erro("Borda esquerda inválida do caractere ",
					x, " da linha ", y));
	if ((x + 1) < map->height)
		if (map->grid[y][x + 1] != '1' && map->grid[y][x + 1] != '0')
			return (border_erro("Borda direita inválida do caractere ",
					x, " da linha ", y));
	return (0);
}

static int	check_char_border(t_map *map, int y, int x, int last_line)
{
	char	not_valid;

	not_valid = 'V';
	if (map->grid[y][x] == 'V')
		not_valid = '0';
	if (y != 0)
		if (map->grid[y - 1][x] == not_valid)
			return (border_erro("Borda superior inválida do caractere ",
					x, " da linha ", y));
	if (y != last_line)
		if (map->grid[y + 1][x] == not_valid)
			return (border_erro("Borda inferior inválida do caractere ",
					x, " da linha ", y));
	if ((x - 1) >= 0)
		if (map->grid[y][x - 1] == not_valid)
			return (border_erro("Borda esquerda inválida do caractere ",
					x, " da linha ", y));
	if ((x + 1) < map->height)
		if (map->grid[y][x + 1] == not_valid)
			return (border_erro("Borda direita inválida do caractere ",
					x, " da linha ", y));
	return (0);
}

static int	check_in_grid(t_game *game, int last_line, int len_line)
{
	int		x;
	int		y;
	int		status;

	x = 0;
	y = -1;
	status = 0;
	while (++y <= last_line)
	{
		len_line = (int)ft_strlen(game->map.grid[y]);
		while (x < len_line)
		{
			if (game->map.grid[y][x] == 'V' || game->map.grid[y][x] == '0'
				|| (game->map.grid[y][x] >= '2' && game->map.grid[y][x] <= '9'))
				status = check_char_border(&game->map, y, x, last_line);
			if (game->map.grid[y][x] == 'N' || game->map.grid[y][x] == 'S'
				|| game->map.grid[y][x] == 'E' || game->map.grid[y][x] == 'W')
				status = check_player_border(&game->map, y, x, last_line);
			x++;
			if (status)
				break ;
		}
		x = 0;
	}
	return (status);
}

static int	check_border_h(t_game *game, int y)
{
	int		end;
	int		start;
	char	*str;

	end = 0;
	start = get_start_line(game, y);
	if (y == 0)
		str = "Borda superior inválida";
	else
		str = "Borda inferior inválida";
	if (start < 0)
		return (border_erro(str, -1, 0, -y));
	end = get_end_line(game, y);
	if (end < 0)
		return (border_erro(str, -1, 0, y));
	while (start < end)
	{
		if (game->map.grid[y][start] == '0')
			break ;
		start++;
	}
	if (start != end)
		return (border_erro(str, -1, 0, -1));
	return (0);
}

int	chekc_map_grid(t_game *game)
{
	int		last_line;

	last_line = (game->map.height - 1);
	if (check_border_h(game, 0))
		return (1);
	if (check_border_h(game, last_line))
		return (1);
	if (check_in_grid(game, last_line, 0))
		return (1);
	return (0);
}
