# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/08 18:23:13 by wdebotte          #+#    #+#              #
#    Updated: 2022/01/08 20:12:54 by wdebotte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf

SRCS		= srcs/main.c

OBJS		= ${SRCS:.c=.o}

CC			= clang
CFLAGS		= -Wall -Wextra -Werror

RM			= rm -rf

PATHLIBS	= libs/

PATHLIBFT	= ${PATHLIBS}libft/
LIBFTFLAG	= -lft
LIBFT		= -L${PATHLIBFT}

PATHMLX		= ${PATHLIBS}minilibx-linux/
MLXFLAGS	= -lmlx -lXext -lX11
MLX			= -L${PATHMLX}

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
				make -C ${PATHLIBFT}
				make -C ${PATHMLX}
				${CC} ${LIBFT} ${MLX} ${OBJS} ${MLXFLAGS} ${LIBFTFLAG} -o ${NAME}

all:		${NAME}

clean:
				make -C ${PATHLIBFT} clean
				make -C ${PATHMLX} clean
				${RM} ${OBJS}

fclean:		clean
				make -C ${PATHLIBFT} fclean
				${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
