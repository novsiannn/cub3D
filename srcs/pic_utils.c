/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pic_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 20:07:43 by ibellash          #+#    #+#             */
/*   Updated: 2023/11/19 18:34:16 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_image	read_xmp_image(void *mlx, char *file)
{
	t_image	sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, file, &sprite.x, &sprite.y);
	if (sprite.xpm_ptr == NULL)
		write(2, SPRITE_ERROR, ft_strlen(SPRITE_ERROR));
	return (sprite);
}

void	my_mlx_pixel_put(t_game *game, int x, int y, uint32_t color)
{
	char	*dst;

	dst = game->rays->img_addr + (y * game->rays->line_length + \
		x * (game->rays->bits_per_pixel / 8));
	*(int *)dst = color;
}
