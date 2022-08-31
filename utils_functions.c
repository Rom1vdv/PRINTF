/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:55:12 by romvan-d          #+#    #+#             */
/*   Updated: 2022/03/11 16:24:11 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_number_len(long int i, int radix)
{
	int	count;

	count = 0;
	if (i == 0)
		return (1);
	if (i < 0)
		count++;
	while (i)
	{	
		i = i / radix;
		count++;
	}
	return (count);
}

int	ft_putnbr_base(long int nb, char *base, int radix)
{
	long int	n;

	n = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= radix)
		ft_putnbr_base(nb / radix, base, radix);
	ft_putchar(base[nb % radix]);
	return (ft_number_len(n, radix));
}

int	ft_putnbr_base_p(unsigned long int nb, char *base, unsigned int radix)
{
	if (nb >= radix)
		ft_putnbr_base_p(nb / radix, base, radix);
	ft_putchar(base[nb % radix]);
	return (ft_number_len_p(nb, radix));
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_number_len_p(unsigned long int i, int radix)
{
	int	count;

	count = 0;
	if (i == 0)
		return (1);
	while (i)
	{	
		i = i / radix;
		count++;
	}
	return (count);
}
