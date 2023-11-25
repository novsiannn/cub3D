/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 20:04:26 by dsas              #+#    #+#             */
/*   Updated: 2023/11/25 15:01:34 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rotate_plus(t_game *d, double rotspeed,\
double old_dir_x, double	old_plane_x)
{
	d->rays->dir_x = d->rays->dir_x
		* cos(-rotspeed) - d->rays->dir_y * sin(-rotspeed);
	d->rays->dir_y = old_dir_x
		* sin(-rotspeed) + d->rays->dir_y * cos(-rotspeed);
	d->rays->plane_x = d->rays->plane_x
		* cos(-rotspeed) - d->rays->plane_y * sin(-rotspeed);
	d->rays->plane_y = old_plane_x
		* sin(-rotspeed) + d->rays->plane_y * cos(-rotspeed);
}

void	rotate(int direction, t_game *d, double rotspeed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = d->rays->dir_x;
	old_plane_x = d->rays->plane_x;
	if (direction == 1)
		rotate_plus(d, rotspeed, old_dir_x, old_plane_x);
	else if (direction == -1)
	{
		d->rays->dir_x = d->rays->dir_x
			* cos(rotspeed) - d->rays->dir_y * sin(rotspeed);
		d->rays->dir_y = old_dir_x
			* sin(rotspeed) + d->rays->dir_y * cos(rotspeed);
		d->rays->plane_x = d->rays->plane_x
			* cos(rotspeed) - d->rays->plane_y * sin(rotspeed);
		d->rays->plane_y = old_plane_x
			* sin(rotspeed) + d->rays->plane_y * cos(rotspeed);
	}
}