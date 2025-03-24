/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:48:42 by efaustin          #+#    #+#             */
/*   Updated: 2025/03/12 15:20:24 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*trim_spaces(char *line, char *srch)
{
	char	*trimmed;

	trimmed = NULL;
	if (line)
	{
		trimmed = ft_strtrim(line, srch);
		free(line);
		if (!trimmed)
		{
			print_erro("Erro ao modificar uma linha do arquivo\n");
			return (NULL);
		}
	}
	return (trimmed);
}

int	is_only_spaces(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	get_line_file(t_game *game)
{
	int		fd;
	char	*line;

	fd = open(game->map.path_file, O_RDONLY);
	if (fd <= 0)
	{
		print_erro("Erro ao abrir o arquivo do mapa\n");
		close(fd);
		return (1);
	}
	line = NULL;
	while (1)
	{
		free(line);
		line = get_next_line(fd, 0);
		if (!line)
			break ;
		game->map.height_file++;
	}
	free(line);
	close(fd);
	return (0);
}
