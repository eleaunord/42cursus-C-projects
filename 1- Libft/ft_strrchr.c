/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:18:57 by eleroty           #+#    #+#             */
/*   Updated: 2023/11/15 12:19:08 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char) c)
			return (((char *) s + i));
		i--;
	}
	return (NULL);
}
/*
#include <stdio.h>
int main(void)
{
    char str[50] = "heohea";

    printf("%s", ft_strrchr(str, 'e'));
}
*/
