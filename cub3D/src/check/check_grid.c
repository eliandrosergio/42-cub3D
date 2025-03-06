#include "cub3d.h"

static int	border_erro(char *str1, int x, char *str2, int y)
{
	print_erro(str1);
	if (x != -1)
		printf("%d", x);
	if (str2)
		printf("%s", str2);
	if (y != -1)
		printf("%d", y);
	printf("\n");
	return (1);
}

static int	check_border_h(t_game *game, int y)
{
    int     end;
    int     start;
	char	*str;

    end = 0;
	start = get_start_line(game, y);
	if (y == 0)
		str = "Borda superior inválida na linha ";
	else
		str = "Borda inferior inválida na linha ";
	if (start < 0)
		return (border_erro(str, -1, 0, -y));
	end = get_end_line(game, y);
	if (end < 0)
		return (border_erro(str, -1, 0, y));
	while (start < end)
	{
		if (game->map.grid[y][start] != '1')
			break ;
		start++;
	}
	if (start != end)
		return (border_erro(str, y, 0, -1));
	return (0);
}

static int	check_char_border(char **grid, int y, int x, int last_line)
{
	if (y != 0)
		if (grid[y - 1][x] != 'V' && grid[y - 1][x] != '1')
			return (border_erro("Borda superior inválida do caractere ",
				x, " da linha ", y));
	if (y != last_line)
		if (grid[y + 1][x] != 'V' && grid[y + 1][x] != '1')
			return (border_erro("Borda inferior inválida do caractere ",
				x, " da linha ", y));
	if (grid[y][x + 1] != 'V' && grid[y][x + 1] != '1')
		return (border_erro("Borda direita inválida do caractere ",
				x, " da linha ", y));
	if (grid[y][x - 1] != 'V' && grid[y][x - 1] != '1')
		return (border_erro("Borda esquerda inválida do caractere ",
				x, " da linha ", y));
	return (0);
}

static int	check_in_grid(t_game *game, int last_line)
{
	int		y;
	int		x;
	int		status;
	int		len_line;

	y = 0;
	x = 0;
	status = 0;
	len_line = 0;
	while (y <= last_line)
	{
		len_line = (int)ft_strlen(game->map.grid[y]);
		while (x < len_line)
		{
			if (game->map.grid[y][x] == 'V')
				status = check_char_border(game->map.grid, y, x, last_line);
			x++;
			if (status)
				break ;
		}
		x = 0;
		y++;
	}
	return (status);
}

int     chekc_map_grid(t_game *game)
{
	int		last_line;

	last_line = (game->map.height - 1);
	if (check_border_h(game, 0))
		return (1);
	if (check_border_h(game, last_line))
		return (1);
	if (check_in_grid(game, last_line))
		return (1);
	return (0);
}
