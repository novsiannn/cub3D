/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:15:52 by dsas              #+#    #+#             */
/*   Updated: 2023/01/10 11:03:25 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(long nb, int *sign)
{
	size_t	len;

	len = 0;
	*sign = 1;
	if (nb < 0)
	{
		len++;
		nb *= -1;
		*sign = -1;
	}
	while (nb >= 1)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*res;
	long	nb;
	int		sign;

	nb = n;
	len = get_len(nb, &sign);
	if (nb == 0)
		return (ft_strdup("0"));
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	if (nb < 0)
		nb *= -1;
	res[len] = '\0';
	while (--len)
	{
		res[len] = (nb % 10) + '0';
		nb /= 10;
	}
	if (sign == -1)
		res[0] = '-';
	else
		res[0] = (nb % 10) + '0';
	return (res);
}
