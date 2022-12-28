CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = do-op
SOURCES = ft_atoi.c do_op.c ft_putchar.c ft_putnbr.c ft_putstr.c main.c
OBJECTS = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I .

clean :
	rm -rf $(OBJECTS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re

