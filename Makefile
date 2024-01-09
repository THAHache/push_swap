SRCS	=	push_swap.c \
			error_control.c \
			free_lst.c \
			order.c \
			num_size.c \
			swap_moves.c \
			push_moves.c \
			rotate_moves.c \
			reverse_rotate_moves.c \
			moves.c \
			few_num.c \
			five_num.c \
			more_num.c

LIBFT	=	libft/

OBJS	=	${SRCS:.c=.o}

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RED		=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
RESET	=	\033[0m

NAME	=	push_swap

.o:	.c
			${CC} ${CFLAGS} -c $< -o $@

${NAME}	:	${OBJS}
			@make -C ${LIBFT}
			@if [ -f ${LIBFT}/libft.a ]; then \
				echo "${GREEN}********* CREATION SUCCESS *********${RESET}"; \
			else \
				echo "${RED}********* FAIL CREATION *********${RESET}"; \
			fi
			@${CC} ${OBJS} -L${LIBFT} -lft -o ${NAME}


all		:	${NAME}

clean	:
			@make -C ${LIBFT} clean
			rm -f ${OBJS}
			@echo "${YELLOW}********* CLEAN SUCCESS *********${RESET}"; \

fclean	:	clean
			@make -C ${LIBFT} fclean
			rm -f ${NAME}
			@echo "${YELLOW}********* FCLEAN SUCCESS *********${RESET}"; \

re		:	fclean all

.PHONY	:	all clean fclean re
