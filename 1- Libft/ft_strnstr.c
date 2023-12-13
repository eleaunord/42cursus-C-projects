/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:12:10 by eleroty           #+#    #+#             */
/*   Updated: 2023/11/24 17:01:02 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	s2_len;
	size_t	i;
	size_t	j;

	i = 0;
	s2_len = ft_strlen(s2);
	if (s2_len == 0)
		return (&*((char *)s1));
	while (i < len && *(s1 + i) != '\0')
	{
		j = 0;
		while (*(s1 + i + j) == *(s2 + j) && j < s2_len && (i + j) < len)
			j++;
		if (j == s2_len)
			return (&*((char *)s1 + i));
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <bsd/string.h>
int main(void)
{
    char gros[50] = "aaabcabcd";
	char petit[50] = "aabc";

    printf("%s", ft_strnstr(gros, petit, 9));
	printf("%c", '\n');
	char gros1[50] = "aaabcabcd";
	char petit1[50] = "aabc";
	printf("%s", strnstr(gros1, petit1, 9));
}
*/
