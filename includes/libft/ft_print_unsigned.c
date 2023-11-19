/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:25:38 by dsas              #+#    #+#             */
/*   Updated: 2023/01/31 18:11:05 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_len(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static char	*ft_unsigned_itoa(unsigned int nb)
{
	char	*nb_string;
	int		len;

	len = nb_len(nb);
	nb_string = (char *)malloc(sizeof(char) * (len + 1));
	if (!nb_string)
		return (0);
	nb_string[len] = '\0';
	if (nb == 0)
		nb_string[0] = '0';
	while (nb != 0)
	{
		nb_string[len - 1] = nb % 10 + '0';
		nb /= 10;
		len--;
	}
	return (nb_string);
}

int	ft_print_unsigned(unsigned int nb)
{
	int		len;
	char	*nb_str;

	nb_str = ft_unsigned_itoa(nb);
	ft_putstr_fd(nb_str, 1);
	len = ft_strlen(nb_str);
	free(nb_str);
	return (len);
}
