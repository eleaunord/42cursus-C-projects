/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:08:51 by eleroty           #+#    #+#             */
/*   Updated: 2023/11/14 16:09:53 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_string;

	new_string = malloc (sizeof(char) * (ft_strlen(s) + 1));
	if (!new_string)
		return (0);
	ft_strlcpy(new_string, s, (ft_strlen(s) + 1));
	return (new_string);
}
