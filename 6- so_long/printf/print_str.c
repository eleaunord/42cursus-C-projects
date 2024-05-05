/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:48:44 by eleroty           #+#    #+#             */
/*   Updated: 2023/12/04 18:34:16 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

int	print_str(va_list lst)
{
	unsigned int	count;
	const char		*string = (const char *)va_arg(lst, const char *);

	count = 0;
	if (!string)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (*string)
	{
		ft_putchar(*string++);
		count++;
	}
	return (count);
}
