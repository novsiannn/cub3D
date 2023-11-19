/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:42:29 by dsas              #+#    #+#             */
/*   Updated: 2022/12/28 15:55:42 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, char const *set)
{
	int	i;

	i = -1;
	while (set[++i])
	{
		if (set[i] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!set)
		return (ft_strdup(s1));
	if (!s1)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (in_set(s1[start], set))
		start++;
	if (start == end)
		return (ft_strdup(""));
	while (in_set(s1[end - 1], set))
		end--;
	return (ft_substr(s1, start, end - start));
}
