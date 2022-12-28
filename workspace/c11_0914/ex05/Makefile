# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinhyepa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 11:49:35 by jinhyepa          #+#    #+#              #
#    Updated: 2022/09/13 16:24:05 by jinhyepa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = do-op
SOURCES = ft_atoi.c ft_do_op.c ft_putchar.c ft_putnbr.c ft_putstr.c main.c
OBJECTS = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME) : ${SOURCES}
	$(CC) $(CFLAGS) $^ -o $@

clean :
	rm -rf $(OBJECTS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
