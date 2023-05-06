# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 19:05:58 by jinhyeok          #+#    #+#              #
#    Updated: 2023/01/28 11:05:07 by jinhyeok         ###   ########.fr        #
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
