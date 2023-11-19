/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:12:27 by dsas              #+#    #+#             */
/*   Updated: 2023/01/31 18:10:56 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printstr(char *str)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_printnbr(int nb)
{
	char	*nb_string;
	int		len;

	nb_string = ft_itoa(nb);
	len = ft_printstr(nb_string);
	free(nb_string);
	return (len);
}

int	ft_print_format(va_list args, char format)
{
	if (format == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		return (1);
	}
	else if (format == 's')
		return (ft_printstr(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_print_ptr(va_arg(args, unsigned long long)));
	else if (format == 'd' || format == 'i')
		return (ft_printnbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), format));
	else if (format == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	size_t	len;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_print_format(args, str[i + 1]);
			i += 2;
		}
		else
		{
			write(1, &(str[i]), 1);
			len++;
			i++;
		}
	}
	return (len);
}
