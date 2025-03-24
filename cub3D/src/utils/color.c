/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:49:16 by efaustin          #+#    #+#             */
/*   Updated: 2025/03/20 22:38:22 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_tab(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
	return ;
}

static int	return_erro_color(int is_two, int *rgb, char **rgb_char)
{
	if (rgb)
		free(rgb);
	if (is_two)
		free_tab((void **)rgb_char);
	return (-1);
}

static int	*copy_to_rgb(char **rgb_to_convert, int *rgb)
{
	int		i;

	i = -1;
	while (rgb_to_convert[++i])
	{
		rgb[i] = ft_atoi(rgb_to_convert[i]);
		if (rgb[i] == -1 || !is_num(rgb_to_convert[i]))
		{
			free_tab((void **)rgb_to_convert);
			free(rgb);
			return (0);
		}
	}
	free_tab((void **)rgb_to_convert);
	return (rgb);
}

static int	convert_rgb(int *rgb_tab)
{
	int		rgb;
	int		r;
	int		g;
	int		b;

	r = rgb_tab[0];
	g = rgb_tab[1];
	b = rgb_tab[2];
	rgb = (((r & 0xff) << 16)
			+ ((g & 0xff) << 8)
			+ (b & 0xff));
	free(rgb_tab);
	return (rgb);
}

int	rgb_to_hex(char *line)
{
	int		i;
	int		*rgb;
	int		count;
	char	**rgb_in_line;

	i = -1;
	rgb = 0;
	count = 0;
	rgb_in_line = ft_split(line, ',');
	while (rgb_in_line[count])
		count++;
	while (count != 3)
		return (return_erro_color(1, rgb, rgb_in_line));
	while (rgb_in_line[++i])
		if (ft_atoi(rgb_in_line[i]) > 255 || ft_atoi(rgb_in_line[i]) < 0)
			return (return_erro_color(1, rgb, rgb_in_line));
	rgb = malloc(sizeof(int) * 3);
	if (!rgb)
		return (return_erro_color(1, rgb, rgb_in_line));
	rgb = copy_to_rgb(rgb_in_line, rgb);
	if (!rgb)
		return (return_erro_color(0, rgb, 0));
	return (convert_rgb(rgb));
}
