# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/08 18:23:13 by wdebotte          #+#    #+#              #
#    Updated: 2022/01/08 23:15:15 by wdebotte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf

SRCS		= srcs/fdf.c

OBJS		= ${SRCS:.c=.o}

CC			= clang
CFLAGS		= -Wall -Wextra -Werror

RM			= rm -rf
MAKE		= make -C

PATHLIBS	= ./libs/

PATHLIBFT	= ${PATHLIBS}./libft/
LIBFTFLAG	= -lft
LIBFT		= -L${PATHLIBFT}

PATHPRINTF	= ${PATHLIBS}./ft_printf/
PRINTFFLAG	= -lftprintf
PRINTF		= -L${PATHPRINTF}

PATHMLX		= ${PATHLIBS}./minilibx-linux/
MLXFLAGS	= -lmlx -lXext -lX11
MLX			= -L${PATHMLX}

LIBSFLAGS	= ${LIBFTFLAG} ${PRINTFFLAG} ${MLXFLAGS}

${NAME}:	${OBJS}
				${MAKE} ${PATHLIBFT}
				${MAKE} ${PATHPRINTF}
				${MAKE} ${PATHMLX}
				${CC} ${LIBFT} ${PRINTF} ${MLX} ${OBJS} ${LIBSFLAGS} -o ${NAME}

all:		${NAME}

clean:
				${MAKE} ${PATHLIBFT} clean
				${MAKE} ${PATHPRINTF} clean
				${MAKE} ${PATHMLX} clean
				${RM} ${OBJS}

fclean:		clean
				${MAKE} ${PATHLIBFT} fclean
				${MAKE} ${PATHPRINTF} fclean
				${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
