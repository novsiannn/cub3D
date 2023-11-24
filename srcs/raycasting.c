/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:03:32 by dsas              #+#    #+#             */
/*   Updated: 2023/11/24 18:39:15 by nikitos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	floor_ceiling_drawing(t_game *game)
{
	int x;
	int y;

	y = -1;
	while (game->screen_height / 2 > ++y)
	{
		x = -1;
		while (game->screen_width > ++x)
			my_mlx_pixel_put(game, x , y, game->ceiling_color);
	}
	y--;
	while (game->screen_height > ++y)
	{
		x = -1;
		while (game->screen_width > ++x)
			my_mlx_pixel_put(game, x , y, game->floor_color);
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
	r->texx =(int)(r->wallx * (double)game->tex_width);
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
		i++;
	}
}

void	check_side(t_game *game)
{
	t_raycast *rays;

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

int draw(t_game *game)
{
	t_raycast *rays;

	game->rays->time = ft_get_ticks();
	rays = game->rays;
	if (rays->img)
		mlx_destroy_image(game->mlx, rays->img);
	rays->img = mlx_new_image(game->mlx, game->screen_width, game->screen_height);
	rays->img_addr = mlx_get_data_addr(rays->img, &rays->bits_per_pixel, &rays->line_length, &rays->endian);
	floor_ceiling_drawing(game);
	walls_drawing(game);
	keys_execute(game);
	mlx_put_image_to_window(game->mlx, game->win, rays->img, 0, 0);
	return 1;
}