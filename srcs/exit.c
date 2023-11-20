/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:29:55 by ibellash          #+#    #+#             */
/*   Updated: 2023/11/20 17:06:31 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_textures(t_game *game)
{
	int	i;

	if (game->texture)
	{
		i = 0;
		while (i < 4)
		{
			if (game->texture[i] != NULL)
				free(game->texture[i]);
			i++;
		}
		free(game->texture);
	}
	if (game->wall_north.xpm_ptr)
		mlx_destroy_image(game->mlx, game->wall_north.xpm_ptr);
	if (game->wall_south.xpm_ptr)
		mlx_destroy_image(game->mlx, game->wall_south.xpm_ptr);
	if (game->wall_west.xpm_ptr)
		mlx_destroy_image(game->mlx, game->wall_west.xpm_ptr);
	if (game->wall_east.xpm_ptr)
		mlx_destroy_image(game->mlx, game->wall_east.xpm_ptr);
}

void	throw_error(t_game *game, char *message)
{
	if (game)
		free_game(game);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	free_game(t_game *game)
{
	free_textures(game);
	if (game->map)
		matrix_free(game->map);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->rays)
		free(game->rays);
}

int	close_game(t_game *game)
{
	free_game(game);
	exit (0);
}
