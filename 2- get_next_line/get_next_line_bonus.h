/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:28:38 by eleroty           #+#    #+#             */
/*   Updated: 2023/11/29 16:30:38 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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

int		found_newline(t_node *lst);
t_node	*ft_lstlast(t_node *lst);
int		len_to_newline(t_node *lst);
void	ft_lstclear(t_node **lst, t_node *clean, char *rest_char);
t_node	*find_last_node(t_node *lst);
void	clean_lst(t_node **lst);
char	*clean_line(t_node *lst);
void	ft_lstadd_back(t_node **lst, char *stock_str, int fd);
void	create_line(t_node **lst, int fd);
char	*get_next_line(int fd);

#endif
