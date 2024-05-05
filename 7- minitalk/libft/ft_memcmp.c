/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:41:58 by eleroty           #+#    #+#             */
/*   Updated: 2023/11/24 16:15:12 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;
	size_t			i;

	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (ptr_s1[i] == ptr_s2[i] && i < n - 1)
		i++;
	return (ptr_s1[i] - ptr_s2[i]);
}

/*
#include <stdio.h>
#include <string.h>
int main ()
{
  char buffer1[] = "ABe";
  char buffer2[] = "ABD";

  int n;

  n=memcmp ( buffer1, buffer2, sizeof(buffer1) );
    printf("%d", ft_memcmp(buffer1, buffer2, sizeof(buffer1)));
    printf("%c", '\n');
    printf("original %d", n);

  return 0;
}
*/
