/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:38:26 by dsas              #+#    #+#             */
/*   Updated: 2022/12/26 14:55:30 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*dst;
	char	*s;

	dst = (char *)dest;
	s = (char *)src;
	if (dest == src)
		return (dest);
	if (s < dst)
	{
		while (len--)
			*(dst + len) = *(s + len);
	}
	else
	{
		while (len--)
			*dst++ = *s++;
	}
	return (dest);
}
