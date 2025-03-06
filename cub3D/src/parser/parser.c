#include "cub3d.h"

static int  get_fd(t_game *game, int *fd)
{
    if (get_line_file(game))
        return (1);
    *fd = open(game->map.path_file, O_RDONLY);
	if (*fd <= 0)
    {
		print_erro("Erro ao abrir o arquivo do mapa\n");
        return (1);
    }
    return (0);
}

static int  get_assets(t_game *game, int *fd, int *i)
{
    int     status;
    char    *line;

    status = 0;
    line = NULL;
    while (*i < game->map.height_file)
    {
        line = get_next_line(*fd, 0);
        line = trim_spaces(line, " \n");
        if (line)
            status = check_param_lines(game, line);
        free(line);
        (*i)++;
        if (status != 0)
            break ;
    }
    (*i)++;
    if (status == 2)
        status = 0;
    return (status);
}

static int  get_map(t_game *game, int *fd, int *i)
{
    int     status;
	char	*line;

    status = 0;
	line = NULL;
    while (*i < game->map.height_file)
    {
        line = get_next_line(*fd, 0);
        line = trim_spaces(line, " \n");
        if (line)
            status = check_map_lines(line);
        if (status != 2)
        {
            free(line);
            (*i)++;
        }
        if (status != 0)
            break ;
    }
    if (status == 0)
        return (return_erro("Mapa não encontrado\n", 0, 0, 0));
    else if (status == 2)
        status = fill_map(game, line, fd, i);
    return (status);
}

int     save_file_info(t_game *game)
{
    int     i;
    int		fd;

    i = 0;
    fd = 0;
    if (get_fd(game, &fd))
        return (1);
    if (get_assets(game, &fd, &i))
        return (1);
    if (get_map(game, &fd, &i))
        return (1);
    return (0);
}
