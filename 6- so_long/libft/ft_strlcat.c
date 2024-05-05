/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:48:10 by eleroty           #+#    #+#             */
/*   Updated: 2023/11/16 21:05:45 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_length;
	size_t	dst_length;

	src_length = ft_strlen(src);
	if (size == 0)
		return (src_length);
	dst_length = ft_strlen(dst);
	if (size < dst_length)
		return (src_length + size);
	i = 0;
	while (src[i] && (dst_length + i) < (size - 1))
	{
		dst[dst_length + i] = src[i];
		i++;
	}
	dst[dst_length + i] = '\0';
	return (src_length + dst_length);
}
