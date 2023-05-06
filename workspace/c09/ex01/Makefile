# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinhyepa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/11 16:17:28 by jinhyepa          #+#    #+#              #
#    Updated: 2022/09/11 16:17:34 by jinhyepa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SOURCES = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_swap.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJECTS = $(SOURCES:.c=.o)
INCLUDES = includes

all : $(NAME)

$(NAME) : $(OBJECTS)
	ar rcs $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c -I $(INCLUDES) $< -o $@

clean :
	rm -rf $(OBJECTS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
