/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:05:14 by dsas              #+#    #+#             */
/*   Updated: 2023/01/10 11:33:47 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;
	char	*res;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (str_len < start)
		return (ft_strdup(""));
	else if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	res = (char *) malloc(len + 1);
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s + start, len + 1);
	return (res);
}
