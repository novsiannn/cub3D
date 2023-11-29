/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:59:53 by ikhristi          #+#    #+#             */
/*   Updated: 2023/11/29 13:08:54 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_components(t_game *game, char **map, int i)
{
	int	j;

	while (map[++i])
	{
		j = -1;
		while (map[i][++j] && map[i][j] != '\n')
		{
			if (map[i][j] == 'N' || map[i][j] == 'W' \
				|| map[i][j] == 'E' || map[i][j] == 'S')
			{
				if (game->player_direction != 0)
					return (0);
				else
				{
					game->player_direction = map[i][j];
					game->rays->pos_x = j;
					game->rays->pos_y = i;
					map[i][j] = '0';
				}
			}
			else if (map[i][j] != ' ' && map[i][j] != '1' && map[i][j] != '0')
				return (0);
		}
	}
	return (1);
}

int	check_walls(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'E' \
									|| map[i][j] == 'S' || map[i][j] == '0')
			{
				if (i == 0 || j == 0 || i == (int)matrix_len(map) - 1 \
										|| j == (int)ft_strlen(map[i]) - 2)
					return (0);
				else if (((int)ft_strlen(map[i - 1]) < j + 2 \
				|| map[i - 1][j] == ' ') || ((int)ft_strlen(map[i + 1]) < j + 1 \
				|| map[i + 1][j] == '\n' || map[i + 1][j] == ' ') \
				|| map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
					return (0);
			}
		}
	}
	return (1);
}

int	check_empty(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (is_empty_line(map[i]))
			break ;
		i++;
	}
	while (map[i])
	{
		if (!is_empty_line(map[i]))
			return (0);
		i++;
	}
	return (1);
}

void	map_check_errors(t_game *game, char **file_content)
{
	if (!check_empty(game->map))
	{
		matrix_free(file_content);
		throw_error(game, MAP_EMPTY_LINES_ERROR);
	}
	if (!check_walls(game->map))
	{
		matrix_free(file_content);
		throw_error(game, MAP_WALL_ERROR);
	}
}
