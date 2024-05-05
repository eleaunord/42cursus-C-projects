/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:10:32 by eleroty           #+#    #+#             */
/*   Updated: 2023/11/14 15:57:21 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		((char *)(dest))[i] = ((const char *)(src))[i];
		i++;
	}
	return (dest);
}

/*
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() 
{ 
	char str[50] = "GeeksForGeeks is for programming geeks.";
    char str1[50] = "GeeksForGeeks is for programming geeks.";
    char * memory = NULL;
    size_t size = 8*sizeof(char);

    memory = (char *) malloc (8*sizeof(char));

	ft_memcpy(memory, str, size);
    printf("After memcpy(): %s", str);
    
    printf("%c", '\n');
 
	memcpy(memory, str1, size); 
	printf("After memcpy(): %s", str1);

    free (memory);
	return 0; 
} 
*/
