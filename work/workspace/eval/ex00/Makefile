SRCS	=	*.c

OBJS	=	*.o

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	rush-02

all		:	${NAME}

${NAME}	:
			${CC} ${CFLAGS} -c ${SRCS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean	:
			rm -f ${OBJS}

fclean	:	clean
			rm -f ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re
