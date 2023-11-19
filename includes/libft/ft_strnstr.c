/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:00:39 by dsas              #+#    #+#             */
/*   Updated: 2022/12/25 15:47:30 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *find, size_t slen)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (find[0] == '\0')
		return ((char *) s);
	while (s[i] != '\0')
	{
		j = 0;
		while (s[i + j] == find[j] && (i + j) < slen)
		{
			if (find[j] == '\0' && s[i + j] == '\0')
				return ((char *) &s[i]);
			j++;
		}
		if (find[j] == '\0')
			return ((char *) &s[i]);
		i++;
	}
	return (NULL);
}
