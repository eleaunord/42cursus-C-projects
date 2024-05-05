/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:03:53 by eleroty           #+#    #+#             */
/*   Updated: 2023/11/16 21:02:06 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	wordcount(char *s, char c)
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

static	char	*wordcopy(char *s, char c, int i)
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

char	**ft_split(char const *s, char c)
{
	int		j;
	int		i;
	char	**tab;

	i = 0;
	j = 0;
	tab = (char **)malloc(sizeof(char *) * (wordcount((char *)s, c) + 1));
	if (!tab || !s)
		return (NULL);
	while (s[i])
	{
		while (s[i] && (s[i] == c))
			i++;
		if (s[i] && (s[i] != c))
		{
			tab[j] = wordcopy((char *)s, c, i);
			j++;
		}
		while (s[i] && (s[i] != c))
			i++;
	}
	tab[j] = 0;
	return (tab);
}

// int	main(int ac, char **av)
// {
// 	char	**tab = ft_split(av[1], ' ');
// 	int		i;
// 	i = 0;

// 	if (ac == 2)
// 	{
// 		while (tab[i])
// 		{
// 			printf("%s\n", tab[i]);
// 			i++;
// 		}
// 	}
// 	else
// 		printf("need 1 arg separated by spaces");
// 	free(tab);
// }
//GOOD
