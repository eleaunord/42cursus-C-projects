/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:04:54 by eleroty           #+#    #+#             */
/*   Updated: 2024/02/01 18:45:28 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	int	word_count(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] && (s[i] == c))
			i++;
		if (s[i] && (s[i] != c))
			count++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (count);
}

static	char	*word_copy(char *s, char c, int i)
{
	int		index;
	char	*word;

	index = 0;
	if (!s)
		return (NULL);
	while (s[i] && (s[i] != c))
	{
		index++;
		i++;
	}
	word = (char *)malloc(sizeof(char) * index + 1);
	if (!word)
		return (NULL);
	i = i - index;
	index = 0;
	while (s[i] && (s[i] != c))
	{
		word[index] = s[i];
		i++;
		index++;
	}
	word[index] = '\0';
	return (word);
}

char	**allocate_and_initialize_tab(char *s, int word_counter)
{
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * (word_counter + 2));
	if (!tab || !s)
		return (NULL);
	return (tab);
}

char	**split(char *s, char c)
{
	int		j;
	int		i;
	int		word_counter;
	char	**tab;

	i = 0;
	j = 0;
	word_counter = word_count((char *)s, c);
	if (!word_counter)
		exit(1);
	tab = allocate_and_initialize_tab(s, word_counter);
	if (!tab || !s)
		return (NULL);
	while (s[i])
	{
		while (s[i] && (s[i] == c))
			i++;
		if (s[i] && (s[i] != c))
			tab[j++] = word_copy((char *)s, c, i);
		while (s[i] && (s[i] != c))
			i++;
	}
	tab[j] = 0;
	return (tab);
}
