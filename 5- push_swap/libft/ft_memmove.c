/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:44:37 by eleroty           #+#    #+#             */
/*   Updated: 2023/11/16 21:07:17 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			temp;
	unsigned int	i;

	if (!dest && !src)
		return (NULL);
	if (src < dest)
	{
		while (n > 0)
		{
			temp = ((char *)(src))[n - 1];
			((char *)(dest))[n - 1] = temp;
			n--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			temp = ((char *)(src))[i];
			((char *)(dest))[i] = temp;
			i++;
		}
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

	ft_memmove(memory, str, size);
    printf("After ft_memmove(): %s", str);
    
    printf("%c", '\n');
 
	memmove(memory, str1, size);
	printf("After memmove(): %s", str1);

    free (memory);
	return 0; 
} 
*/
