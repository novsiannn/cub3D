/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:11:46 by dsas              #+#    #+#             */
/*   Updated: 2023/01/31 18:11:17 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ptr_len(unsigned long long ptr)
{
	int	len;

	len = 0;
	while (ptr != 0)
	{
		ptr /= 16;
		len++;
	}
	return (len);
}

static void	ft_put_ptr(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_put_ptr(ptr / 16);
		ft_put_ptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd((ptr + '0'), 1);
		else
			ft_putchar_fd((ptr - 10 + 'a'), 1);
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	ft_putstr_fd("0x", 1);
	if (ptr == 0)
	{
		ft_putchar_fd('0', 1);
		return (3);
	}
	else
	{
		ft_put_ptr(ptr);
		return (ptr_len(ptr) + 2);
	}
}
