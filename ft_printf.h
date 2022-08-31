/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:20:50 by romvan-d          #+#    #+#             */
/*   Updated: 2022/03/04 15:24:40 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
size_t	ft_strlen(char *str);
int		ft_putchar(char c);
size_t	ft_putstr(char *str);
int		ft_putnbr_base(long int nb, char *base, int radix);
int		ft_number_len(long int i, int radix);
int		ft_putnbr_base_p(unsigned long int nb, char *base, unsigned int radix);
int		ft_number_len_p(unsigned long int i, int radix);

#endif