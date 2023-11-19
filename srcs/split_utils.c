/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:45:31 by ibellash          #+#    #+#             */
/*   Updated: 2023/08/03 18:04:07 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_count(char const *s)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (*s)
	{
		if (!ft_isspace(*s) && k == 0)
		{
			k = 1;
			i++;
		}
		else if (ft_isspace(*s))
			k = 0;
		s++;
	}
	return (i);
}

char	*fill(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc(sizeof(char) * ((finish - start) + 1));
	while (start < finish)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split_spaces(char *s)
{
	size_t	i;
	size_t	j;
	int		k;
	char	**temp;

	temp = malloc(sizeof(char *) * (ft_count(s) + 1));
	if (temp == NULL)
		return (NULL);
	i = 0;
	j = 0;
	k = -1;
	while (i <= ft_strlen(s))
	{
		if (!ft_isspace(s[i]) && k < 0)
			k = i;
		else if ((ft_isspace(s[i]) || i == ft_strlen(s)) && k >= 0)
		{
			temp[j++] = fill(s, k, i);
			k = -1;
		}
		i++;
	}
	temp[j] = 0;
	return (temp);
}
