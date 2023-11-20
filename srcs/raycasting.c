/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:03:32 by dsas              #+#    #+#             */
/*   Updated: 2023/11/20 18:31:05 by novsiann         ###   ########.fr       */
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
	keys_execute(game);
	mlx_put_image_to_window(game->mlx, game->win, rays->img, 0, 0);
	return 1;
}