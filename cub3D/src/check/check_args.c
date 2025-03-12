/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:47:40 by efaustin          #+#    #+#             */
/*   Updated: 2025/03/12 15:20:24 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_path_file(t_game *game, char *file)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(file);
	game->map.path_file = ft_calloc((len + 1), sizeof (char));
	if (!game->map.path_file)
		return (return_erro("Erro ao alocar o ficheiro do Mapa\n", 0, 0, 0));
	while (i < len)
	{
		game->map.path_file[i] = file[i];
		i++;
	}
	game->map.path_file[i] = '\0';
	return (0);
}

int	check_args(int ac, char **av, t_game *game)
{
	if (ac != 2)
		return (return_erro("Use: ", av[0], " mapa.cub\n", 0));
	if (ac == 2 && check_extension(av[1], ".cub"))
		return (return_erro("Use um arquivo de extensão .cub\n", 0, 0, 0));
	if (ac == 2 && check_file(av[1]))
		return (return_erro("Não foi possivel acessar o arquivo do mapa\n",
				0, 0, 0));
	ft_path_file(game, av[1]);
	if (ac == 2 && save_file_info(game))
		return (1);
	if (ac == 2 && chekc_map_grid(game))
		return (1);
	return (0);
}
