/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:25:20 by dsas              #+#    #+#             */
/*   Updated: 2023/01/27 15:49:49 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strdup(const char *s)
// {
// 	char	*new_string;
// 	int		size;
// 	int		i;

// 	i = 0;
// 	size = ft_strlen(s) + 1;
// 	new_string = (char *)malloc(sizeof(char) * (size));
// 	if (new_string == NULL)
// 		return (NULL);
// 	while (s[i])
// 	{
// 		new_string[i] = s[i];
// 		i++;
// 	}
// 	new_string[i] = '\0';
// 	return (new_string);
// }

// void	*ft_memmove(void *dest, const void *src, size_t len)
// {
// 	char	*dst;
// 	char	*s;

// 	dst = (char *)dest;
// 	s = (char *)src;
// 	if (dest == src)
// 		return (dest);
// 	if (s < dst)
// 	{
// 		while (len--)
// 			*(dst + len) = *(s + len);
// 	}
// 	else
// 	{
// 		while (len--)
// 			*dst++ = *s++;
// 	}
// 	return (dest);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t	s1_len;
// 	size_t	s2_len;
// 	char	*res;

// 	if (!s1 && !s2)
// 		return (ft_strdup(""));
// 	else if (!s1)
// 		return (ft_strdup(s2));
// 	else if (!s2)
// 		return (ft_strdup(s1));
// 	s1_len = ft_strlen(s1);
// 	s2_len = ft_strlen(s2);
// 	res = (char *) malloc(s1_len + s2_len + 1);
// 	if (!res)
// 		return (NULL);
// 	ft_memmove(res, s1, s1_len);
// 	ft_memmove(res + s1_len, s2, s2_len + 1);
// 	return (res);
// }

int	ft_strchr_line(const char *s, int c)
{
	int	i;
	int	len;

	len = ft_strlen(s);
	i = -1;
	while (++i <= len)
	{
		if (s[i] == (unsigned char) c)
			return (i);
	}
	return (-1);
}
