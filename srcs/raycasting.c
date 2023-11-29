/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:03:32 by dsas              #+#    #+#             */
/*   Updated: 2023/11/25 15:13:28 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	floor_ceiling_drawing(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->screen_height / 2 > ++y)
	{
		x = -1;
		while (game->screen_width > ++x)
			my_mlx_pixel_put(game, x, y, game->ceiling_color);
	}
	y--;
	while (game->screen_height > ++y)
	{
		x = -1;
		while (game->screen_width > ++x)
			my_mlx_pixel_put(game, x, y, game->floor_color);
	}
}

void	calc_draw(t_game *game)
{
	t_raycast	*r;

	r = game->rays;
	r->line_height = (int)(game->screen_height / r->perp_wall_dist);
	r->draw_start = -r->line_height / 2 + game->screen_height / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = r->line_height / 2 + game->screen_height / 2;
	if (r->draw_end >= game->screen_height)
		r->draw_end = game->screen_height - 1;
	r->texnum = game->map[r->map_y][r->map_x] - 48;
	if (r->side % 2 == 0)
		r->wallx = r->pos_y + r->perp_wall_dist * r->ray_dir_y;
	else
		r->wallx = r->pos_x + r->perp_wall_dist * r->ray_dir_x;
	r->wallx -= floor(r->wallx);
	r->texx = (int)(r->wallx * (double)game->tex_width);
}

void	draw_walls(t_game *game, int i)
{
	int			j;
	t_raycast	*r;

	r = game->rays;
	if (r->side % 2 == 0 && r->ray_dir_x > 0)
		r->texx = game->tex_width - r->texx - 1;
	if (r->side % 2 == 1 && r->ray_dir_y < 0)
		r->texx = game->tex_width - r->texx - 1;
	r->step = 1.0 * game->tex_height / r->line_height;
	r->texpos = (r->draw_start - game->screen_height / 2 + \
								r->line_height / 2) * r->step;
	j = r->draw_start;
	while (j < r->draw_end)
	{
		r->texy = (int)r->texpos & (game->tex_height - 1);
		r->texpos += r->step;
		r->colr = game->texture[r->texnum + r->side - 1] \
		[game->tex_height * r->texy + r->texx];
		my_mlx_pixel_put(game, i, j, r->colr);
		j++;
	}
}

void	walls_drawing(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->screen_width)
	{
		init_wall_drawing(game, i);
		calc_side_dist(game);
		calc_hit(game);
		calc_draw(game);
		draw_walls(game, i);
		i++;
	}
}

void	check_side(t_game *game)
{
	t_raycast	*rays;

	rays = game->rays;
	if (rays->side == 0)
	{
		if (rays->map_x > rays->pos_x)
			rays->side = 2;
		rays->perp_wall_dist = rays->side_dist_x - rays->delta_dist_x;
	}
	else
	{
		if (rays->map_y > rays->pos_y)
			rays->side = 3;
		rays->perp_wall_dist = rays->side_dist_y - rays->delta_dist_y;
	}
}
