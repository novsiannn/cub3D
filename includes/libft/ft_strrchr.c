/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:14:24 by dsas              #+#    #+#             */
/*   Updated: 2022/12/12 17:19:28 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	len;

	len = ft_strlen(s);
	i = -1;
	while (++i <= len)
	{
		if (s[len - i] == (unsigned char) c)
			return ((char *) &s[len - i]);
	}
	return (NULL);
}
