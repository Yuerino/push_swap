SHELL	= /bin/sh

NAME	= fdf

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

MINILIBX_DIR	= ./minilibx-linux
LIBFT_DIR		= ./libft
X11_INC			= /usr/X11/include
X11_LIB			= /usr/X11/lib

LFLAGS	= -L${LIBFT_DIR} -L${MINILIBX_DIR} -L${X11_LIB} -lft -lmlx -lXext -lX11 -lm

IDIR	= .
IFLAGS	= -I${IDIR} -I${LIBFT_DIR} -I${MINILIBX_DIR} -I${X11_INC}

SRCS	= main.c fdf.c read.c utils.c controls.c render.c project.c

RM		= rm -f

.PHONY: all clean fclean re bonus debug

${NAME}: ${SRCS}
		@make -C ${MINILIBX_DIR}
		@make bonus -C ${LIBFT_DIR}
		${CC} ${CFLAGS} ${SRCS} ${IFLAGS} ${LFLAGS} -o ${NAME}

debug: ${SRSC}
		@make -C ${MINILIBX_DIR}
		@make bonus -C ${LIBFT_DIR}
		${CC} -g ${CFLAGS} ${SRCS} ${IFLAGS} ${LFLAGS} -o ${NAME}-debug

all: ${NAME}

bonus: all

clean:
		@${RM} ${NAME} ${NAME}-debug
		@make clean -C ${LIBFT_DIR}
		@make clean -C ${MINILIBX_DIR}

fclean: clean
		@make fclean -C ${LIBFT_DIR}

re: fclean all
