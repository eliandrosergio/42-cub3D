/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tex_clr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:48:01 by efaustin          #+#    #+#             */
/*   Updated: 2025/03/20 22:01:01 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	verific_texture_line(char *line)
{
	int		len;

	len = ft_strlen(line);
	len--;
	if (line[len] && (line[len] == '\n'))
		line[len] = '\0';
	if (check_extension(line, ".xpm"))
		return (return_erro("Use uma textura de extensão .xpm\n", 0, 0, line));
	if (check_file(line))
		return (return_erro("Não foi possivel acessar o arquivo da textura\n",
				0, 0, line));
	return (0);
}

static int	check_texture(t_game *game, char *line, char dir)
{
	char	*temp;

	temp = ft_strdup(line + 2);
	if (!temp)
		return (return_erro("Falha ao alocar memória da textura\n", 0, 0, 0));
	line = trim_spaces(temp, " ");
	if (!line)
		return (return_erro("Falha ao alocar memória da textura\n", 0, 0, 0));
	if (verific_texture_line(line))
		return (1);
	if (dir == 'E')
		game->textures.east.path = line;
	else if (dir == 'N')
		game->textures.north.path = line;
	else if (dir == 'S')
		game->textures.south.path = line;
	else if (dir == 'W')
		game->textures.west.path = line;
	else if (dir == 'C')
		game->textures.ceiling.path = line;
	else if (dir == 'F')
		game->textures.floor.path = line;
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
	else if (!ft_strncmp("CE ", line, 2))
		status = check_texture(game, line, 'C');
	else if (!ft_strncmp("FL ", line, 2))
		status = check_texture(game, line, 'F');
	else
		return (return_erro("Indentificador Desconhecido ou "
				"Indentificador em Falta\n", 0, 0, 0));
	if (game->textures.east.path && game->textures.north.path
		&& game->textures.south.path && game->textures.west.path
		&& game->textures.ceiling.path && game->textures.floor.path)
		status = 2;
	return (status);
}
