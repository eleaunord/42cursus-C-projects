/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:15:58 by eleroty           #+#    #+#             */
/*   Updated: 2023/11/29 16:26:33 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <stdio.h>

void	clean_lst(t_node **lst)
{
	t_node	*last;
	t_node	*clean;
	int		i;
	int		x;
	char	*rest_char;

	rest_char = malloc(BUFFER_SIZE + 1);
	clean = malloc(sizeof(t_node));
	if (!rest_char || !clean)
		return ;
	last = ft_lstlast(*lst);
	i = 0;
	x = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	while (last->content[i] && last->content[i++])
		rest_char[x++] = last->content[i];
	rest_char[x] = '\0';
	clean->content = rest_char;
	clean->next = NULL;
	ft_lstclear(lst, clean, rest_char);
}

char	*clean_line(t_node *lst)
{
	char	*line;
	int		i;
	int		x;

	line = malloc(len_to_newline(lst) + 1);
	if (!line || !lst)
		return (NULL);
	x = 0;
	while (lst)
	{
		i = 0;
		while (lst->content[i])
		{
			if (lst->content[i] == '\n')
			{
				line[x] = '\n';
				line[x + 1] = '\0';
				return (line);
			}
			line[x++] = lst->content[i++];
		}
		lst = lst->next;
	}
	line[x] = '\0';
	return (line);
}

void	ft_lstadd_back(t_node **lst, char *stock_str, int fd)
{
	t_node	*new;
	t_node	*last;

	last = ft_lstlast(lst[fd]);
	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	if (!last)
		lst[fd] = new;
	else
		last->next = new;
	new->content = stock_str;
	new->next = NULL;
}

void	create_line(t_node **lst, int fd)
{
	int		bytes_read;	
	char	*stock_str;

	while (!found_newline(lst[fd]))
	{
		stock_str = malloc(BUFFER_SIZE + 1);
		if (!stock_str)
			return ;
		bytes_read = read(fd, stock_str, BUFFER_SIZE);
		if (!bytes_read)
		{
			free(stock_str);
			return ;
		}
		stock_str[bytes_read] = '\0';
		ft_lstadd_back(lst, stock_str, fd);
	}
}

char	*get_next_line(int fd)
{
	static t_node	*lst[1024];
	char			*next_line;

	if (fd < 0 || fd > 1025 || BUFFER_SIZE <= 0
		|| read(fd, &next_line, 0) == -1)
		return (NULL);
	create_line(lst, fd);
	if (!lst[fd])
	{
		while (fd > 0)
		{
			free(lst[fd]);
			fd--;
		}
		return (NULL);
	}
	next_line = clean_line(lst[fd]);
	clean_lst(&lst[fd]);
	return (next_line);
}
