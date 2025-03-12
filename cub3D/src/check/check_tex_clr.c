/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tex_clr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:48:01 by efaustin          #+#    #+#             */
/*   Updated: 2025/03/12 12:48:02 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_texture(t_game *game, char *line, char dir)
{
	char	*temp;

	temp = ft_strdup(line + 2);
	if (!temp)
		return (return_erro("Falha ao alocar memória da textura\n", 0, 0, 0));
	line = trim_spaces(temp, " ");
	if (!line)
		return (return_erro("Falha ao alocar memória da textura\n", 0, 0, 0));
	if (check_extension(line, ".xpm"))
		return (return_erro("Use uma textura de extensão .xpm\n", 0, 0, line));
	if (check_file(line))
		return (return_erro("Não foi possivel acessar o arquivo da textura\n",
				0, 0, line));
	if (dir == 'E')
		game->textures.east.path = line;
	else if (dir == 'N')
		game->textures.north.path = line;
	else if (dir == 'S')
		game->textures.south.path = line;
	else if (dir == 'W')
		game->textures.west.path = line;
	return (0);
}

static int	check_color(t_game *game, char *line, char c)
{
	int		color;
	char	*temp;

	temp = ft_strdup(line + 1);
	if (!temp)
		return (return_erro("Falha ao alocar memória da cor\n", 0, 0, 0));
	line = trim_spaces(temp, " ");
	if (!line)
		return (return_erro("Falha ao alocar memória da cor\n", 0, 0, 0));
	color = rgb_to_hex(line);
	free(line);
	if (!color)
		return (return_erro("Código da Cor Inválido\n", 0, 0, 0));
	if (c == 'F')
		game->map.floor = color;
	else if (c == 'C')
		game->map.ceiling = color;
	return (0);
}

int	check_param_lines(t_game *game, char *line)
{
	int		status;

	status = 0;
	if (line && (line[0] == '\0' || line[0] == '\n'))
		return (0);
	else if (!ft_strncmp("SO ", line, 3))
		status = check_texture(game, line, 'S');
	else if (!ft_strncmp("WE ", line, 3))
		status = check_texture(game, line, 'W');
	else if (!ft_strncmp("EA ", line, 3))
		status = check_texture(game, line, 'E');
	else if (!ft_strncmp("NO ", line, 3))
		status = check_texture(game, line, 'N');
	else if (!ft_strncmp("F ", line, 2))
		status = check_color(game, line, 'F');
	else if (!ft_strncmp("C ", line, 2))
		status = check_color(game, line, 'C');
	else
		return (return_erro("Indentificador Desconhecido\n", 0, 0, 0));
	if (game->textures.east.path && game->textures.north.path
		&& game->textures.south.path && game->textures.west.path
		&& game->map.floor && game->map.ceiling)
		status = 2;
	return (status);
}
