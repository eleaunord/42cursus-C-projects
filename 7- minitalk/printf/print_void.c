/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_void.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:49:03 by eleroty           #+#    #+#             */
/*   Updated: 2023/12/04 18:34:26 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen_hex(unsigned long n)
{
	int	size;

	size = 0;
	while (n)
	{
		size++;
		n /= 16;
	}
	return (size);
}

int	hexa_converter(unsigned long n, int base)
{
	int		count_char;
	char	*hexa_base;

	hexa_base = "0123456789abcdef";
	count_char = ft_strlen_hex(n);
	if (base == 1)
		hexa_base = "0123456789ABCDEF";
	if (n < 16)
		ft_putchar(hexa_base[n]);
	else
	{
		hexa_converter((n / 16), base);
		hexa_converter((n % 16), base);
	}
	return (count_char);
}

int	print_void(va_list lst)
{
	unsigned long	count;
	void			*ptr;

	ptr = (void *)va_arg(lst, void *);
	if (ptr == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	ft_putstr("0x");
	count = hexa_converter((unsigned long)ptr, 0);
	if (count != 0)
		return (count + 2);
	else
		return (3);
}
