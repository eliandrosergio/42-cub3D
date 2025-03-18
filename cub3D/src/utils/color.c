/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:49:16 by efaustin          #+#    #+#             */
/*   Updated: 2025/03/12 15:20:24 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_colorcode(char *line)
{
	int		i;
	int		commas;

	i = -1;
	commas = 0;
	while (line[++i])
	{
		if (ft_strchr_int("0123456789 ,", line[i]))
			return (1);
		if (line[i] == ',')
			commas++;
	}
	if (commas != 2)
		return (1);
	return (0);
}

int	rgb_to_hex(char *line)
{
	int		i;
	int		j;
	int		rgb[3];

	i = 0;
	j = 0;
	if (check_colorcode(line))
		return (0);
	while (i < 3)
		rgb[i++] = 0;
	while (line[i] && ++j < 3)
	{
		while (line[i] && !is_num(line[i]))
			i++;
		while (is_num(line[i]))
		{
			rgb[j] = rgb[j] * 10;
			rgb[j] = rgb[j] + (line[i] - '0');
			i++;
		}
		if (rgb[j] > 255 || rgb[j] < 0)
			return (0);
	}
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}
