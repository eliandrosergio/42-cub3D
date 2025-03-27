/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:29:04 by efaustin          #+#    #+#             */
/*   Updated: 2025/03/20 22:31:02 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	perform_dda(t_ray *ray, t_map *map)
{
	int		hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (map->grid[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
	return ;
}

static void	calc_wall_tex(t_game *game)
{
	if (game->ray.side == 0)
		game->ray.wall_x = game->player.pos_y
			+ game->ray.perp_wall_dist * game->ray.dir_y;
	else
		game->ray.wall_x = game->player.pos_x
			+ game->ray.perp_wall_dist * game->ray.dir_x;
	game->ray.wall_x -= floor(game->ray.wall_x);
	return ;
}

static void	calculate_wall_params(t_game *game, t_wall *data)
{
	data->line_height = (int)(HEIGHT / game->ray.perp_wall_dist);
	data->draw_start = -(data->line_height) / 2 + HEIGHT / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = (data->line_height) / 2 + HEIGHT / 2;
	if (data->draw_end >= HEIGHT)
		data->draw_end = HEIGHT - 1;
	data->tex_x = (int)(game->ray.wall_x * TEXWIDTH);
	if (game->ray.side == 0 && game->ray.dir_x > 0)
		data->tex_x = TEXWIDTH - data->tex_x - 1;
	if (game->ray.side == 1 && game->ray.dir_y < 0)
		data->tex_x = TEXWIDTH - data->tex_x - 1;
	data->step = 1.0 * TEXHEIGHT / (data->line_height);
	data->tex_pos = (data->draw_start - HEIGHT / 2
			+ (data->line_height) / 2) * (data->step);
	return ;
}

static void	draw_wall(t_game *game, int x)
{
	int		tex_y;
	int		color;
	t_wall	data;
	t_img	texture;

	calculate_wall_params(game, &data);
	if (game->ray.side == 0 && game->ray.dir_x > 0)
		texture = game->textures.east;
	else if (game->ray.side == 0 && game->ray.dir_x < 0)
		texture = game->textures.west;
	else if (game->ray.side == 1 && game->ray.dir_y < 0)
		texture = game->textures.north;
	else
		texture = game->textures.south;
	while (data.draw_start < data.draw_end)
	{
		tex_y = (int)data.tex_pos & (TEXHEIGHT - 1);
		data.tex_pos += data.step;
		color = get_pixel_color(&texture, data.tex_x, tex_y);
		my_mlx_pixel_put(&game->img, x, data.draw_start, color);
		data.draw_start++;
	}
	return ;
}

void	draw_ray(t_game *game, int x)
{
	perform_dda(&game->ray, &game->map);
	calc_wall_tex(game);
	game->ray.wall_distances[x] = game->ray.perp_wall_dist;
	draw_wall(game, x);
	return ;
}
