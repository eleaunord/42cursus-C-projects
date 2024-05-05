/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:23:33 by eleroty           #+#    #+#             */
/*   Updated: 2023/12/04 18:48:36 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	int_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_count(unsigned int n)
{
	unsigned int	count_num;

	count_num = 1;
	while (n > 9)
	{
		n /= 10;
		count_num *= 10;
	}
	return (count_num);
}

int	print_dec(va_list lst)
{
	unsigned int	abs;
	unsigned int	n;
	unsigned int	count_num;
	unsigned int	count;
	int				d;

	count = 0;
	d = va_arg(lst, int);
	if (d < 0)
	{
		abs = (d * -1);
		count += int_putchar('-');
	}
	else
		abs = d;
	n = abs;
	count_num = ft_count(n);
	while (count_num >= 1)
	{
		count += int_putchar(((abs / count_num) % 10) + '0');
		count_num /= 10;
	}
	return (count);
}
