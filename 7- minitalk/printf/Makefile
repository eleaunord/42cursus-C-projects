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