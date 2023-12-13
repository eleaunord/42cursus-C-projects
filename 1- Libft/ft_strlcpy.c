/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:54:18 by eleroty           #+#    #+#             */
/*   Updated: 2023/11/09 11:56:38 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_size;

	src_size = ft_strlen(src);
	if (!dst || !src || !size)
		return (src_size);
	i = 0;
	while (i < (size - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_size);
}

/*
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
int main(void)
{
    char src[50]= "hey0";
    char dest[50];
    size_t size = 3;
    
    printf("After ft_strlcpy(): %zu", ft_strlcpy(dest, src, size));
}
*/
