/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:47:54 by eleroty           #+#    #+#             */
/*   Updated: 2023/11/09 10:53:36 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_bzero(void *s, size_t bytes)
{
	size_t	i;

	i = 0;
	while (i < bytes)
	{
		((unsigned char *)(s))[i] = '\0';
		i++;
	}
	return (s);
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

	ft_bzero(str, size);
    printf("After ft_bzero(): %s", str);
    
    printf("%c", '\n');

	// Fill 8 characters starting from str[13] with '.' 
	bzero(str1, size); 
	printf("After bzero(): %s", str1); 
	return 0; 
} 
*/
