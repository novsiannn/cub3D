/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:47:03 by dsas              #+#    #+#             */
/*   Updated: 2023/01/31 18:11:39 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	hex_len(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

static void	ft_put_hex(unsigned int nb, char format)
{
	if (nb >= 16)
	{
		ft_put_hex(nb / 16, format);
		ft_put_hex(nb % 16, format);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((nb - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((nb - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hex(unsigned int nb, char format)
{
	if (nb == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	ft_put_hex(nb, format);
	return (hex_len(nb));
}
