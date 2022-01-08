NAME		= fdftest

SRCS		= main.c

OBJS		= ${SRCS:.c=.o}

CC		= clang
RM		= rm -rf
CFLAGS		= -Wall -Wextra -Werror

PATHMLX		= ../minilibx-linux/
MLXFLAGS	= -lmlx -lXext -lX11

${NAME}:	${OBJS}
			make -C ${PATHMLX}
			${CC} -L${PATHMLX} ${OBJS} ${MLXFLAGS} -o ${NAME}

all:		${NAME}

clean:
			make -C ${PATHMLX} clean
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re
