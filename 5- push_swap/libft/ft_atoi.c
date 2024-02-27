/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:56:04 by eleroty           #+#    #+#             */
/*   Updated: 2024/01/19 17:25:21 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_it_space(const char num)
{
	if (num == 32 || (num >= 9 && num <= 13))
		return (0);
	else
		return (1);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	i;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (is_it_space(nptr[i]) == 0)
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
/*
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
    char    val[10] = "+110";

    printf("%d", ft_atoi(val));
    printf("%c", '\n');
    printf("%d", atoi(val));
}
*/
