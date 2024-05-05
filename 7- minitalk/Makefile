
NAMESERVER = server
NAMECLIENT = client

NAMESERVER_BONUS = server_bonus
NAMECLIENT_BONUS = client_bonus

SRCSERVER = server.c
SRCCLIENT = client.c

SRCSERVER_BONUS = bonus/server_bonus.c
SRCCLIENT_BONUS = bonus/client_bonus.c

LIBFT_DIR = ./libft
PRINTF_DIR = ./printf

SRCLIBFT = libft/ft_atoi.c \
                          libft/ft_bzero.c \
                          libft/ft_calloc.c \
                          libft/ft_isalnum.c \
                          libft/ft_isalpha.c \
                          libft/ft_isascii.c \
                          libft/ft_isdigit.c \
                          libft/ft_isprint.c \
                          libft/ft_itoa.c \
                          libft/ft_lstadd_back.c \
                          libft/ft_lstadd_front.c \
                          libft/ft_lstclear.c \
                          libft/ft_lstdelone.c \
                          libft/ft_lstiter.c \
                          libft/ft_lstlast.c \
                          libft/ft_lstmap.c \
                          libft/ft_lstnew.c \
                          libft/ft_lstsize.c \
                          libft/ft_memchr.c \
                          libft/ft_memcmp.c \
                          libft/ft_memcpy.c \
                          libft/ft_memmove.c \
                          libft/ft_memset.c \
                          libft/ft_putchar_fd.c \
                          libft/ft_putendl_fd.c \
                          libft/ft_putnbr_fd.c \
                          libft/ft_putstr_fd.c \
                          libft/ft_split.c \
                          libft/ft_strchr.c \
                          libft/ft_strdup.c \
                          libft/ft_striteri.c \
                          libft/ft_strjoin.c \
                          libft/ft_strlcat.c \
                          libft/ft_strlcpy.c \
                          libft/ft_strlen.c \
                          libft/ft_strmapi.c \
                          libft/ft_strncmp.c \
                          libft/ft_strnstr.c \
                          libft/ft_strrchr.c \
                          libft/ft_strtrim.c \
                          libft/ft_substr.c \
                          libft/ft_tolower.c \
                          libft/ft_toupper.c \
                          libft/ft_strncpy.c \

OBJLIBFT = $(SRCLIBFT:.c=.o)
HEADERLIBFT = $(LIBFT_DIR)/libft.h

SRCPRINTF =      printf/print_char.c \
                          printf/print_dec.c \
                          printf/ft_printf.c \
                          printf/print_hexa_low.c \
                          printf/print_hexa_up.c \
                          printf/print_un.c \
                          printf/print_void.c \
                          printf/print_str.c \

OBJPRINTF = $(SRCPRINTF:.c=.o)
HEADERPRINTF = $(PRINTF_DIR)/printf.h

FLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR) -I$(PRINTF_DIR)
CC = clang

OBJSERVER = $(SRCSERVER:.c=.o) $(OBJLIBFT) $(OBJPRINTF)
OBJCLIENT = $(SRCCLIENT:.c=.o) $(OBJLIBFT) $(OBJPRINTF)

OBJSERVER_BONUS = $(SRCSERVER_BONUS:.c=.o) $(OBJLIBFT) $(OBJPRINTF)
OBJCLIENT_BONUS = $(SRCCLIENT_BONUS:.c=.o) $(OBJLIBFT) $(OBJPRINTF)

all: $(NAMESERVER) $(NAMECLIENT)

$(NAMESERVER): $(OBJSERVER)
	$(CC) $(OBJSERVER) -o $(NAMESERVER)

$(NAMECLIENT): $(OBJCLIENT)
	$(CC) $(OBJCLIENT) -o $(NAMECLIENT)

$(NAMESERVER_BONUS): $(OBJSERVER_BONUS)
	$(CC) $(OBJSERVER_BONUS) -o $(NAMESERVER_BONUS)

$(NAMECLIENT_BONUS): $(OBJCLIENT_BONUS)
	$(CC) $(OBJCLIENT_BONUS) -o $(NAMECLIENT_BONUS)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

bonus: $(NAMESERVER_BONUS) $(NAMECLIENT_BONUS)

clean:
	rm -rf $(OBJSERVER) $(OBJCLIENT) $(OBJSERVER_BONUS) $(OBJCLIENT_BONUS)

fclean: clean
	rm -rf $(NAMESERVER) $(NAMECLIENT) $(NAMESERVER_BONUS) $(NAMECLIENT_BONUS)

re: fclean all

.PHONY: all clean fclean re

