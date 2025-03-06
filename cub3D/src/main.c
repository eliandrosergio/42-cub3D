#include "cub3d.h"

int     main(int ac, char **av)
{
    t_game  game;

    if (init_data(&game))
        cleanup_exit(&game, 1);
    if (check_args(ac, av, &game))
        cleanup_exit(&game, 1);
    printf("Inicio do game\n");
    cleanup_exit(&game, 0);
    return (0);
}
