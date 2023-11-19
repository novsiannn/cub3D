/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:44:39 by dsas              #+#    #+#             */
/*   Updated: 2023/08/01 15:48:05 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	*convert(unsigned char *img_data, int img_width, int img_height)
{
	int	*int_array;
	int	i;
	int	j;
	int	k;

	int_array = (int *) malloc(img_width * img_height * sizeof(int));
	if (int_array == NULL)
		return (NULL);
	i = -1;
	while (++i < img_height)
	{
		j = -1;
		while (++j < img_width)
		{
			k = (i * img_width + j) * 4;
			int_array[i * img_width + j] = (img_data[k + 3] << 24) | \
			(img_data[k + 2] << 16) | (img_data[k + 1] << 8) | img_data[k];
		}
	}
	return (int_array);
}

int	init_textures(t_game *g)
{
	unsigned char	*img_data;
	int				bpp;

	bpp = 0;
	img_data = (unsigned char *)mlx_get_data_addr(g->wall_east.xpm_ptr, &bpp, \
											&g->size_line, &g->rays->endian);
	g->texture[0] = (uint32_t *)convert(img_data, g->tex_width, g->tex_height);
	if (g->texture[0] == NULL)
		return (0);
	img_data = (unsigned char *)mlx_get_data_addr(g->wall_north.xpm_ptr, &bpp, \
											&g->size_line, &g->rays->endian);
	g->texture[1] = (uint32_t *)convert(img_data, g->tex_width, g->tex_height);
	if (g->texture[1] == NULL)
		return (0);
	img_data = (unsigned char *)mlx_get_data_addr(g->wall_west.xpm_ptr, &bpp, \
											&g->size_line, &g->rays->endian);
	g->texture[2] = (uint32_t *)convert(img_data, g->tex_width, g->tex_height);
	if (g->texture[2] == NULL)
		return (0);
	img_data = (unsigned char *)mlx_get_data_addr(g->wall_south.xpm_ptr, &bpp, \
											&g->size_line, &g->rays->endian);
	g->texture[3] = (uint32_t *)convert(img_data, g->tex_width, g->tex_height);
	if (g->texture[3] == NULL)
		return (0);
	return (1);
}
