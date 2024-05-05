/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:15:27 by jdecorte          #+#    #+#             */
/*   Updated: 2024/04/05 16:48:26 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*ft_strjoin_mod(char *s1, const char *s2);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strchr_mod(const char *s, int c);
size_t	ft_strclen(const char *s, int c);
char	*get_leftover(char *memory);
char	*get_line(char *memory);
char	*store_chunks(int fd, char *memory);
char	*get_next_line(int fd);

#endif
