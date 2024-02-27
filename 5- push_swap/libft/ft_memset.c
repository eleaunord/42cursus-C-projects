/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:52:36 by eleroty           #+#    #+#             */
/*   Updated: 2023/11/16 21:09:01 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t bytes)
{
	size_t	i;

	i = 0;
	while (i < bytes)
	{
		((unsigned char *)(pointer))[i] = value;
		i++;
	}
	return (pointer);
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
    size_t size = 8*sizeof(char);

	ft_memset(str + 13, '.', size);
    printf("After memset(): %s", str);
    
    printf("%c", '\n');

	// Fill 8 characters starting from str[13] with '.' 
	memset(str1 + 13, '.', size); 
	printf("After memset(): %s", str1); 
	return 0; 
} 
*/
