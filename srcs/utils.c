/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:36:54 by ibellash          #+#    #+#             */
/*   Updated: 2023/11/19 17:09:27 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_if_nums(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_isspace(int c)
{
	if ((c < 9 || c > 13) && c != 32)
		return (0);
	return (1);
}

size_t	matrix_len(char **str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	**matrix_dup(char **str, int size)
{
	char	**res;
	int		i;

	res = (char **)ft_calloc(sizeof(char *), size + 1);
	i = 0;
	while (i < size)
	{
		res[i] = ft_strdup(str[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

void	matrix_free(char **str)
{
	int	size;
	int	i;

	i = 0;
	size = matrix_len(str);
	while (i < size)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

unsigned int	ft_get_ticks(void)
{
	struct timespec	now;

	clock_gettime(CLOCK_MONOTONIC, &now);
	return ((now.tv_sec * 1000) + (now.tv_nsec / 1000000));
}
