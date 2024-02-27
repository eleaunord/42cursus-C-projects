/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:21:44 by eleroty           #+#    #+#             */
/*   Updated: 2024/01/31 17:08:41 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_space(const char num)
{
	if (num == 32 || (num >= 9 && num <= 13))
		return (0);
	else
		return (1);
}

long	ft_atol(const char *nptr)
{
	long	sign;
	long	i;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (is_space(nptr[i]) == 0)
		i++;
	if (nptr[i] == 45 || nptr[i] == 43)
	{
		if (nptr[i] == 45)
			sign = -1;
		i++;
	}
	if (nptr[i] >= '0' && nptr[i] <= '9')
	{
		while (nptr[i] >= '0' && nptr[i] <= '9')
		{
			res = res * 10 + (nptr[i++] - '0');
		}
	}
	else
		return (0);
	return (res * sign);
}
