/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:03:27 by eleroty           #+#    #+#             */
/*   Updated: 2023/11/14 16:05:46 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	if (nmemb == 0 || size == 0)
	{
		mem = malloc(1);
		return (mem);
	}
	if ((nmemb * size) < size || (nmemb * size) < nmemb)
		return (0);
	mem = (void *)malloc(nmemb * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, nmemb * size);
	return (mem);
}
// #include <stdio.h>
// int main(void)
// {
//     int*    ptr;

//     ptr = (int*)ft_calloc(100, 4);    
// }
