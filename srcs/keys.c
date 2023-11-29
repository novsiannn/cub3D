/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:44:10 by dsas              #+#    #+#             */
/*   Updated: 2023/11/25 14:57:05 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_press(int key, t_game *game)
{
	if (key == 53)
		game->key_esc = 1;
	if (key == 1)
		game->key_s = 1;
	if (key == 13)
		game->key_w = 1;
	if (key == 0)
		game->key_a = 1;
	if (key == 2)
		game->key_d = 1;
	if (key == 123)
		game->key_left = 1;
	if (key == 124)
		game->key_right = 1;
	return (0);
}

int	key_release(int key, t_game *game)
{
	if (key == 53)
		game->key_esc = 0;
	if (key == 1)
		game->key_s = 0;
	if (key == 13)
		game->key_w = 0;
	if (key == 0)
		game->key_a = 0;
	if (key == 2)
		game->key_d = 0;
	if (key == 123)
		game->key_left = 0;
	if (key == 124)
		game->key_right = 0;
	return (0);
}

int	keys_execute(t_game *game)
{
	if (game->key_esc)
		close_game(game);
	if (game->key_w)
		key_up(game);
	if (game->key_s)
		key_down(game);
	if (game->key_a)
		key_a(game);
	if (game->key_d)
		key_d(game);
	if (game->key_left)
		rotate(-1, game, game->rotspeed);
	if (game->key_right)
		rotate(1, game, game->rotspeed);
	return (0);
}
