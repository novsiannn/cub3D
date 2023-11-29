/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:03:32 by ikhristi          #+#    #+#             */
/*   Updated: 2023/11/29 13:12:03 by ikhristi         ###   ########.fr       */
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
	char	*str;
	int		i;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		throw_error(game, FILE_ERROR);
	res = ft_calloc(sizeof(char *), count_lines(fd) + 1);
	close(fd);
	if (!res)
		return (NULL);
	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	i = 0;
	while (str)
	{
		res[i] = str;
		str = get_next_line(fd);
		i++;
	}
	res[i] = NULL;
	close(fd);
	return (res);
}
