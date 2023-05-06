# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/29 15:36:32 by jinhyeok          #+#    #+#              #
#    Updated: 2023/01/30 10:38:33 by jinhyeok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = do-op
SOURCES = ft_atoi.c ft_main.c ft_putnbr.c
OBJECTS = ft_atoi.o ft_main.o ft_putnbr.o

all : $(NAME)

$(NAME) : $(SOURCES)
	$(CC) $(CFLAGS) $^ -o $@

clean :
	rm -rf $(OBJECTS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
