/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:49:19 by eleroty           #+#    #+#             */
/*   Updated: 2023/12/04 18:49:44 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_count(unsigned int n);
int		int_putchar(char c);
int		print_hexa_up(va_list lst, int base);
int		print_hexa_low(va_list lst, int base);
int		print_un(va_list lst);
int		print_dec(va_list lst);
void	ft_putchar(char c);
int		print_char(va_list lst);
void	ft_putstr(char *s);
int		print_str(va_list lst);
int		ft_hex_len(unsigned int n);
int		hexa_converter(unsigned long n, int base);
int		ft_putnbr(unsigned int n);
int		print_void(va_list lst);
int		arborescent(va_list *lst, const char *format, unsigned int *i);
int		ft_printf(const char *format, ...);
#endif
