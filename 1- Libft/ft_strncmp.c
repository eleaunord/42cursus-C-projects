/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:41:58 by eleroty           #+#    #+#             */
/*   Updated: 2023/11/16 20:44:14 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n && (str1[i] || str2[i]))
	{
		if (str1[i] != str2[i] || !str1[i] || !str2[i])
			return ((str1[i]) - (str2[i]));
		i++;
		n--;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
//     printf("%d", ft_strncmp("ABJ", "ABC", 4));
// 	printf("%d", strncmp("ABJ", "ABC", 4));
// }
