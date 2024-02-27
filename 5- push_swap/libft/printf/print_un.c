/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_un.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:48:54 by eleroty           #+#    #+#             */
/*   Updated: 2023/12/04 18:38:08 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(unsigned int n)
{
	int	counter;

	counter = 0;
	if (n > 9)
		counter += ft_putnbr((n / 10));
	ft_putchar((n % 10) + 48);
	counter++;
	return (counter);
}

int	print_un(va_list lst)
{
	unsigned long	count;
	unsigned int	u;

	count = 0;
	u = (unsigned int)va_arg(lst, unsigned int);
	count += ft_putnbr(u);
	return (count);
}
