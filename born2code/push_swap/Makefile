# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 15:09:00 by jinhyeok          #+#    #+#              #
#    Updated: 2023/05/26 13:11:44 by jinhyeok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = push_swap.c check_input.c stack.c list_util.c \
list_util2.c utils.c check_input_util.c sorting.c \
command2.c shortsort.c shortsort_utils.c mergesort.c merge_hardcode.c\
 merge_hardcode_utils.c  mergesort_utils.c tri_to_a.c to_a_up.c\
  to_a_down.c tri_utils.c tri_to_b.c to_b_up.c to_b_down.c tri_utils2.c \
  command.c ft_split.c ft_isdigit.c mergesort_utils2.c
B_SOURCES = checker.c checker_utils.c get_next_line.c command.c \
command2.c list_util.c list_util2.c check_input.c check_input_util.c \
stack.c tri_utils.c utils.c ft_split.c ft_isdigit.c tri_utils2.c get_next_line_utils.c

M_OBJ = $(SOURCES:.c=.o)
B_OBJ = $(B_SOURCES:.c=.o)

ifdef BONUS
	OBJECTS = $(B_OBJ)
	NAME = checker
else
	OBJECTS = $(M_OBJ)
	NAME = push_swap
endif

all	: $(NAME)

$(NAME) : $(OBJECTS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
bonus :
	make BONUS=1 all
clean :
	rm -rf $(M_OBJ) $(B_OBJ)

fclean : clean
	rm -rf push_swap
	rm -rf checker

re :
	make fclean
	make all

.PHONY : all clean fclean re bonus