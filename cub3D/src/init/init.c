#include "cub3d.h"

int     init_data(t_game *game)
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
