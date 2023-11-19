/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 19:04:28 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/31 15:59:06 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	**get_map(char **file_content)
{
	int		var_count;
	char	**map;
	int		i;
	int		j;

	var_count = 0;
	i = 0;
	while (file_content[i])
	{
		if (!is_empty_line(file_content[i]))
		{
			if (var_count == 6)
				break ;
			var_count++;
		}
		i++;
	}
	if (!file_content[i])
		return (NULL);
	j = matrix_len(file_content) - 1;
	while (is_empty_line(file_content[j]))
		j--;
	map = matrix_dup(&file_content[i], j - i + 1);
	return (map);
}

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	count_lines(int fd)
{
	int		i;
	char	*s;

	i = 0;
	s = get_next_line(fd);
	while (s)
	{
		free(s);
		s = get_next_line(fd);
		i++;
	}
	return (i);
}

char	**read_map(t_game *game, char *map)
{
	char	**res;
	int		fd;
	char	*s;
	int		i;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		throw_error(game, FILE_ERROR);
	res = ft_calloc(sizeof(char *), count_lines(fd) + 1);
	if (!res)
		return (NULL);
	close(fd);
	fd = open(map, O_RDONLY);
	s = get_next_line(fd);
	i = 0;
	while (s)
	{
		res[i] = s;
		s = get_next_line(fd);
		i++;
	}
	res[i] = 0;
	close(fd);
	return (res);
}
