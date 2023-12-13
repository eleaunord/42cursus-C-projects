/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:21:31 by eleroty           #+#    #+#             */
/*   Updated: 2023/11/15 12:24:35 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_s;
	size_t	s_length;
	size_t	i;

	if (!s)
		return (NULL);
	s_length = ft_strlen(s);
	if (s_length <= len + start)
		len = s_length - start;
	if (s_length < start)
	{
		new_s = malloc(1);
		new_s[0] = '\0';
		return (new_s);
	}
	new_s = (char *)malloc((sizeof(*s) * (len + 1)));
	if (!new_s)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
		new_s[i++] = s[start++];
	new_s[i] = '\0';
	return (new_s);
}
/*
#include <stdio.h>
int main(void)
{
    printf("%s", ft_substr("hey bob!", 5, 2));
    return(0);
}
*/
