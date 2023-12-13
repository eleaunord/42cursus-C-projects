/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:12:44 by eleroty           #+#    #+#             */
/*   Updated: 2023/11/16 21:07:54 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_length;
	size_t	i;
	size_t	j;
	char	*new_s;
	size_t	s2_length;

	if (!s1 || !s2)
		return (NULL);
	s2_length = ft_strlen(s2);
	total_length = ft_strlen(s1) + ft_strlen(s2);
	new_s = (char *)malloc(sizeof(char) * (total_length + 1));
	if (!new_s)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		new_s[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
		new_s[i++] = s2[j++];
	new_s[i] = '\0';
	return (new_s);
}

// #include <stdio.h>

// int main(void)
// {
//     printf("%s", ft_strjoin("hi ", "bob!"));
// }
