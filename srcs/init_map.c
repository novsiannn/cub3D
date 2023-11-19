/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:39:58 by ibellash          #+#    #+#             */
/*   Updated: 2023/08/03 17:55:41 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	add_color_vars(int *color, char *rgb)
{
	char	**colors;
	int		i;

	colors = ft_split(rgb, ',');
	i = 0;
	while (colors[i])
	{
		if (*color != 0 || (i == 3 || (i < 2 && !colors[i + 1])) \
			|| !check_if_nums(colors[i]) || ft_atoi(colors[i]) > 255)
		{
			write(2, MAP_ARGS_COLOR_ERROR, ft_strlen(MAP_ARGS_COLOR_ERROR));
			matrix_free(colors);
			return (1);
		}
		i++;
	}
	*color = create_trgb(0, ft_atoi(colors[0]), \
		ft_atoi(colors[1]), ft_atoi(colors[2]));
	matrix_free(colors);
	return (0);
}

int	add_path_vars(t_game *game, t_image *image, char *path)
{
	if ((*image).xpm_ptr != NULL)
		return (1);
	*image = read_xmp_image(game->mlx, path);
	if ((*image).xpm_ptr == NULL)
		return (1);
	return (0);
}

int	pick_vars(t_game *game, char **var)
{
	if (!ft_strncmp(var[0], "NO", 3))
		return (add_path_vars(game, &game->wall_north, var[1]));
	if (!ft_strncmp(var[0], "SO", 3))
		return (add_path_vars(game, &game->wall_south, var[1]));
	if (!ft_strncmp(var[0], "WE", 3))
		return (add_path_vars(game, &game->wall_west, var[1]));
	if (!ft_strncmp(var[0], "EA", 3))
		return (add_path_vars(game, &game->wall_east, var[1]));
	if (!ft_strncmp(var[0], "F", 2))
		return (add_color_vars(&game->floor_color, var[1]));
	if (!ft_strncmp(var[0], "C", 2))
		return (add_color_vars(&game->ceiling_color, var[1]));
	return (1);
}

void	init_map_vars(t_game *game, char **file)
{
	int		i;
	int		count;
	char	**temp;

	i = 0;
	count = 0;
	while (file[i])
	{
		temp = ft_split_spaces(file[i]);
		if (*temp != NULL)
		{
			if (matrix_len(temp) != 2 || pick_vars(game, temp))
			{
				matrix_free(file);
				matrix_free(temp);
				throw_error(game, MAP_ARGS_ERROR);
			}
			else
				count++;
		}
		matrix_free(temp);
		if (count == 6)
			break ;
		i++;
	}
}

void	init_map(t_game *game, char **file_content)
{
	int	i;

	game->map = get_map(file_content);
	if (!game->map)
	{
		matrix_free(file_content);
		throw_error(game, MAP_EMPTY_ERROR);
	}
	map_check_errors(game, file_content);
	fill_with_ones(game);
	i = -1;
	if (!check_components(game, game->map, i))
	{
		matrix_free(file_content);
		throw_error(game, MAP_COMPONENTS_ERROR);
	}
}
