/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:03:32 by dsas              #+#    #+#             */
/*   Updated: 2023/11/21 18:55:02 by novsiann         ###   ########.fr       */
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

void	walls_drawing(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->screen_width)
	{
		init_wall_drawing(game, i);
		i++;
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