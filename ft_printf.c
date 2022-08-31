/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:53:33 by romvan-d          #+#    #+#             */
/*   Updated: 2022/03/04 15:22:47 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			ft_putchar(str[i]);
			i++;
		}
		return (i);
	}
	return (write(1, "(null)", 6));
}

int	ft_check_charset(char c, char const *set)
{
	int	i;

	i = 0;
	if (set)
	{
		while (set[i])
		{
			if (set[i] == c)
				return (1);
			i++;
		}
	}
	return (0);
}

int	ft_check_arguments(char conv, va_list args)
{
	if (conv == 'd' || conv == 'i')
		return (ft_putnbr_base((va_arg(args, int)), "0123456789", 10));
	else if (conv == 'u')
		return (ft_putnbr_base((va_arg(args, unsigned int)), "0123456789", 10));
	else if (conv == 'x')
		return (ft_putnbr_base((va_arg(args, unsigned int)),
				"0123456789abcdef", 16));
	else if (conv == 'X')
		return (ft_putnbr_base((va_arg(args, unsigned int)),
				"0123456789ABCDEF", 16));
	else if (conv == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (conv == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (conv == '%')
		return (ft_putchar('%'));
	else if (conv == 'p')
	{
		write(1, "0x", 2);
		return (ft_putnbr_base_p((va_arg(args, unsigned long int)),
				"0123456789abcdef", 16) + 2);
	}
	return (0);
}	

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		len;

	if (!str)
		return (0);
	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%' && ft_check_charset(str[i + 1], "cspiudxX%"))
		{
			len += (ft_check_arguments(str[i + 1], args));
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
