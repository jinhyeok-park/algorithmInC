CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = ft_changemap.c ft_checkchar.c ft_linecheck.c ft_logic.c ft_main.c ft_makemap.c ft_makemap2.c ft_mapcheck.c ft_print.c ft_standard_output.c ft_free.c ft_submain.c
NAME = bsq
INC = ft.h
OBJC = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJC)
	$(CC) $(CFLAGS) $^ -I $(INC) -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -I $(INC) -o $@

clean:
	rm -rf $(OBJC)

fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY: re clean fclean all
