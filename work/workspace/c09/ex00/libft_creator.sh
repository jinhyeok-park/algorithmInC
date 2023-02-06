# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 15:21:57 by jinhyeok          #+#    #+#              #
#    Updated: 2023/01/28 10:42:13 by jinhyeok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

gcc -c ft_putchar.c ft_strcmp.c ft_putstr.c ft_strlen.c ft_swap.c ft_putstr.c
ar -rsc libft.a ft_putchar.o ft_swap.o ft_putstr.o ft_putchar.o ft_swap.o ft_putstr.o
