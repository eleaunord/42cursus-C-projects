# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 14:29:44 by sycourbi          #+#    #+#              #
#    Updated: 2023/11/14 14:53:42 by sycourbi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = philo.c \
		init.c \
		life.c \
		utils.c \
		check_death.c \

OBJ = $(SRC:.c=.o)

CC = cc

CFLAG = -Wall -Wextra -Werror 

all: $(NAME)

%.o: %.c
	$(CC) -c $(CFLAG) $< -o $@ -I.
# -c sert a creer fichier objet
# -o sert a creer le fichier executable
# -I sert a inclure les header (.h)

$(NAME): $(OBJ)
	$(CC) -pthread -lpthread $(CFLAG) -o $(NAME) $(OBJ) -I.

clean:
	rm -f $(OBJ)
# -r sert a effacer recursivement les sous repertoires
# -f sert a ne pas demander de confirmation d'effacement, et ne pas renvoyer de code erreur quand le fichier n'existe pas

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
