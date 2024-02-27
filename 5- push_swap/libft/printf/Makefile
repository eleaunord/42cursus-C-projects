# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 17:03:09 by eleroty           #+#    #+#              #
#    Updated: 2024/01/19 17:03:10 by eleroty          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Werror -Wextra
SRCS = ft_printf.c \
print_char.c \
print_dec.c \
print_hexa_low.c \
print_hexa_up.c \
print_str.c \
print_void.c \
print_un.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus