#include "cub3d.h"

char    *trim_spaces(char *line, char *srch)
{
    char    *trimmed;

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

int     get_line_file(t_game *game)
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
