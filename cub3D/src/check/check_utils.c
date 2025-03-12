/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:48:06 by efaustin          #+#    #+#             */
/*   Updated: 2025/03/12 15:20:24 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_extension(char *str, char *key)
{
	int		start;
	int		i;

	start = (int)(ft_strlen(str) - ft_strlen(key));
	if (start <= 0)
		return (1);
	i = 0;
	while (start && str[start] && key[i] && (str[start] == key[i]))
	{
		start++;
		i++;
	}
	if (i == (int)ft_strlen(key))
		return (0);
	return (1);
}

int	check_file(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	if (close(fd) < 0)
		return (1);
	return (0);
}

int	get_start_line(t_game *game, int y)
{
	int		i;

	i = 0;
	while (game->map.grid[y][i])
	{
		if (game->map.grid[y][i] == '1')
			return (i);
		i++;
	}
	return (-1);
}

int	get_end_line(t_game *game, int y)
{
	int		i;

	i = ((int)ft_strlen(game->map.grid[y])) - 1;
	while (game->map.grid[y][i])
	{
		if (game->map.grid[y][i] == '1')
			return (i);
		i--;
	}
	return (-1);
}
