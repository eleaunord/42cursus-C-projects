/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:12:10 by eleroty           #+#    #+#             */
/*   Updated: 2023/11/16 20:58:00 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*str;

	i = 0;
	str = (unsigned char *) s;
	while (i < n)
	{
		if (*str == (unsigned char) c)
			return (str);
		i++;
		str++;
	}
	return (NULL);
}
// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
//     char s[] = {0, 1, 2 ,3 ,4 ,5};

//     char * found = ft_memchr(s, 0, 1);
//     printf("%s", found);
//     printf("%c", '\n');

// 	char s1[] = {0, 1, 2 ,3 ,4 ,5};
//     char * find = memchr(s1, 0, 1);
//     printf("%s", find);
// }
