# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 21:30:27 by jinhyeok          #+#    #+#              #
#    Updated: 2023/06/11 14:51:49 by jinhyeok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
SOURCES = main.c init.c map_checker.c map_checker2.c map_checker3.c so_long.c \
          so_long_utils.c free.c get_next_line.c get_next_line_utils.c error.c
INCLUDES = includes

M_OBJ = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(M_OBJ)
	make -C ft_printf
	make -C mlx
	cp ./mlx/libmlx.dylib ./libmlx.dylib
	$(CC) $^ -Lft_printf -lftprintf -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@ -I $(INCLUDES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(M_OBJ)
	make -C ft_printf clean
	make -C mlx clean

fclean: clean
	rm -rf $(NAME)
	rm -rf ./ft_printf/libftprintf.a
	rm -rf ./mlx/libmlx.dylib
	rm -rf libmlx.dylib

re: fclean all

.PHONY: all clean fclean re