#include "cub3d.h"

static void free_grid(char **grid, int height)
{
    int     i;

    i = 0;
    while (i <= height)
    {
        free(grid[i]);
        i++;
    }
    free(grid);
    grid = NULL;
    return ;
}

char        **allocate_grid(int width, int height)
{
    int     i;
    char    **grid;

    i = 0;
    grid = ft_calloc((height + 1), sizeof(char *));
    if (!grid)
    {
        perror("Erro ao alocar a grelha do mapa\n");
        free(grid);
        return (NULL);
    }
    while (i < height)
    {
        grid[i] = ft_calloc(width, sizeof(int));
        if (!grid[i])
        {
            perror("Erro ao alocar linha da grelha do mapa\n");
            free_grid(grid, i);
            return (NULL);
        }
        i++;
    }
    return (grid);
}
/*
int         load_texture(t_game *game, char tex_dir)
{
    int     width;
    int     height;
    t_img   *texture;
    
    if (tex_dir == 'E')
        texture = &game->textures.east;
    else if (tex_dir == 'N')
        texture = &game->textures.north;
    else if (tex_dir == 'W')
        texture = &game->textures.west;
    else if (tex_dir == 'S')
        texture = &game->textures.south;
    texture->img = mlx_xpm_file_to_image(game->mlx, texture->path, &width, &height);
    if (!texture->img)
        return (1);
    texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel,
        &texture->line_length, &texture->endian);
    return (0);
}*/
