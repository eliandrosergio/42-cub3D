/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:41:30 by efaustin          #+#    #+#             */
/*   Updated: 2025/03/18 10:41:33 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_pixel_color(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return ;
}

void	draw_ceiling_and_floor(t_game *game)
{
	int		x;
	int		y;
	int		color;
	int		midset;

	x = 0;
	y = 0;
	midset = HEIGHT / 2;
	color = game->map.ceiling;
	while (y <= HEIGHT)
	{
		if (color == game->map.ceiling && y >= midset)
			color = game->map.floor;
		while (x < WIDTH)
			my_mlx_pixel_put(&game->img, x++, y, color);
		x = 0;
		y++;
	}
	return ;
}
