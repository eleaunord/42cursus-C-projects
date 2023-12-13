/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:15:11 by eleroty           #+#    #+#             */
/*   Updated: 2023/11/29 16:15:44 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10 
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	char			*content;
	struct s_node	*next;
}				t_node;

int		is_newline(t_node *lst);
t_node	*ft_lstlast(t_node *lst);
char	*clean_line(t_node *lst);
void	copy_str(t_node *lst, char *str);
int		char_counter(t_node *lst);
void	clean_lst(t_node **lst);
char	*get_next_line(int fd);
void	ft_lstclear(t_node **lst, t_node *clean, char *rest_char);
void	create_line(t_node **lst, int fd);
void	ft_lstadd_back(t_node **lst, char *stock_str);

#endif
