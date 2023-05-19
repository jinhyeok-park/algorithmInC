# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 15:09:00 by jinhyeok          #+#    #+#              #
#    Updated: 2023/05/19 19:57:39 by jinhyeok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SOURCES = push_swap.c check_input.c stack.c list_util.c \
list_util2.c utils.c check_input_util.c sorting.c \
command2.c shortsort.c shortsort_utils.c mergesort.c merge_hardcode.c\
 merge_hardcode_utils.c  mergesort_utils.c tri_to_a.c to_a_up.c\
  to_a_down.c tri_utils.c tri_to_b.c to_b_up.c to_b_down.c tri_utils2.c \
  command.c ft_split.c ft_isdigit.c mergesort_utils2.c

M_OBJ = $(SOURCES:.c=.o)

all	: $(NAME)

$(NAME) : $(M_OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(M_OBJ)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re bonus
