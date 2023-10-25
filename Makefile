SRCS    = push_swap.c \
			libft.c \
			moves.c
#			checkmove.c

OBJS    = ${SRCS:.c=.o}

CC      = gcc

CFLAGS  = -Wall -Wextra -Werror

NAME    = push_swap

#.c.o :       ${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

.o: libft/%.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}		:	${OBJS}
				make -C libft/
#				ar rc ${NAME} ${OBJS}

all 		:   ${NAME}

clean 		:
				make -C libft/ fclean
				rm -f ${OBJS}

fclean 		:	clean
				rm -f ${NAME} libft/*.o *.o

re 			:   fclean all

.PHONY		:	all clean fclean re
