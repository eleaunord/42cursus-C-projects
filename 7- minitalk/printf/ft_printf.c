/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:49:46 by eleroty           #+#    #+#             */
/*   Updated: 2023/12/04 18:00:04 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	arborescent(va_list *lst, const char *format, unsigned int *i)
{
	unsigned int	count_char;

	count_char = 0;
	if (format[*i] == 'c')
		count_char += print_char(*lst);
	else if (format[*i] == 's')
		count_char += print_str(*lst);
	else if (format[*i] == 'p')
		count_char += print_void(*lst);
	else if (format[*i] == 'd' || format[*i] == 'i')
		count_char += print_dec(*lst);
	else if (format[*i] == 'u')
		count_char += print_un(*lst);
	else if (format[*i] == 'x')
		count_char += print_hexa_low(*lst, 0);
	else if (format[*i] == 'X')
		count_char += print_hexa_up(*lst, 1);
	else if (format[*i] == '%')
	{
		ft_putchar('%');
		return (1);
	}
	return (count_char);
}

int	ft_printf(const char *format, ...)
{
	va_list			lst;
	unsigned int	count_char;
	unsigned int	i;

	count_char = 0;
	i = 0;
	va_start(lst, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count_char += arborescent(&lst, format, &i);
		}
		else
		{
			ft_putchar(format[i]);
			count_char++;
		}
		i++;
	}
	va_end(lst);
	return (count_char);
}
