/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:34:25 by dsas              #+#    #+#             */
/*   Updated: 2023/11/25 13:18:17 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_wall_drawing(t_game *game, int i)
{
	t_raycast *rays;

	rays = game->rays;
	rays->camera_x = 2 * i / (double)game->screen_height - 1;
	rays->ray_dir_x = rays->dir_x + rays->plane_x * rays->camera_x;
	rays->ray_dir_y = rays->dir_y + rays->plane_y * rays->camera_x;
	rays->map_x = (int)rays->pos_x;
	rays->map_y = (int)rays->pos_y;
	rays->delta_dist_x = fabs(1 / rays->ray_dir_x);
	rays->delta_dist_y = fabs(1 / rays->ray_dir_y);
	rays->hit = 0;
}

void	calc_side_dist_y(t_game *game)
{
	t_raycast *rays;

	rays = game->rays;
	if (rays->ray_dir_y < 0)
	{
		rays->step_y = -1;
		rays->side_dist_y = (rays->pos_y - rays->map_y) * rays->delta_dist_y;
	}
	else
	{
		rays->step_y = 1;
		rays->side_dist_y = (rays->map_y + 1.0 - rays->pos_y) * rays->delta_dist_y;
	}
}

void	calc_side_dist(t_game *game)
{
	t_raycast *rays;

	rays = game->rays;
	if (rays->ray_dir_x < 0)
	{
		rays->step_x = -1;
		rays->side_dist_x = (rays->pos_x - rays->map_x) * rays->delta_dist_x;
	}
	else
	{
		rays->step_x = 1;
		rays->side_dist_x = (rays->map_x + 1.0 - rays->pos_x) * rays->delta_dist_x;
	}
	calc_side_dist_y(game);
}

void	calc_hit(t_game *game)
{
	t_raycast *rays;

	rays = game->rays;
	while (rays->hit == 0)
	{
		if (rays->side_dist_x < rays->side_dist_y)
		{
			rays->side_dist_x += rays->delta_dist_x;
			rays->map_x += rays->step_x;
			rays->side = 0;
		}
		else
		{
			rays->side_dist_y += rays->delta_dist_y;
			rays->map_y += rays->step_y;
			rays->side = 1;
		}
		if (game->map[rays->map_y][rays->map_x] > '0')
			rays->hit = 1;
	}
	check_side(game);
}
