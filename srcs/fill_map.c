/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:55:37 by ikhristi          #+#    #+#             */
/*   Updated: 2023/11/27 17:55:45 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	find_max_len(t_game *game)
{
	int		max;
	int		i;

	i = 0;
	max = 0;
	while (game->map[i])
	{
		if ((int)ft_strlen(game->map[i]) > max)
		{
			max = (int)ft_strlen(game->map[i]);
			if (game->map[i][(int)ft_strlen(game->map[i] - 1)] != '\n')
				max++;
		}
		i++;
	}
	return (max);
}

void	fill_with_ones(t_game *game)
{
	int		max;
	int		i;
	int		j;
	char	*new;

	i = 0;
	max = find_max_len(game);
	while (game->map[i])
	{
		if ((int)ft_strlen(game->map[i]) < max)
		{
			new = malloc(max + 1);
			ft_strlcpy(new, game->map[i], max);
			j = (int)ft_strlen(new) - 2;
			while (++j < max - 1)
				new[j] = '1';
			new[j] = '\n';
			new[j + 1] = 0;
			free(game->map[i]);
			game->map[i] = new;
		}
		i++;
	}
}
