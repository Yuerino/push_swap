SHELL	= /bin/sh

NAME	= push_swap

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

LIBFT_DIR = ./libft

LFLAGS	= -L${LIBFT_DIR} -lft

IDIR	= .
IFLAGS	= -I${IDIR} -I${LIBFT_DIR}

SRCS	= main.c operations.c utils.c parser.c sort.c

RM		= rm -f

.PHONY: all clean fclean re bonus debug

${NAME}: ${SRCS}
		@make extra -C ${LIBFT_DIR}
		${CC} ${CFLAGS} ${SRCS} ${IFLAGS} ${LFLAGS} -o ${NAME}

debug: ${SRSC}
		@make extra -C ${LIBFT_DIR}
		${CC} -g ${CFLAGS} ${SRCS} ${IFLAGS} ${LFLAGS} -o ${NAME}-debug

all: ${NAME}

bonus: all

clean:
		@${RM} ${NAME} ${NAME}-debug
		@make clean -C ${LIBFT_DIR}

fclean: clean
		@make fclean -C ${LIBFT_DIR}

re: fclean all
