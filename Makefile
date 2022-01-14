# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/08 18:23:13 by wdebotte          #+#    #+#              #
#    Updated: 2022/01/14 15:30:58 by wdebotte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CYAN		= \033[0m\033[96m
GREEN		= \033[1m\033[92m

PREFIX		= \n${GREEN}=> ${CYAN}[${GREEN}FdF${CYAN}] 

NAME		= fdf

SRCS		= srcs/fdf.c srcs/checkmap.c srcs/utils.c srcs/putimg.c

HEADERS		= headers/fdf.h headers/fdf_structures.h

OBJS		= ${SRCS:.c=.o}

CC			= clang
CFLAGS		= -Wall -Wextra -Werror -g

RM			= rm -rf
MAKE		= make -C

NORM		= norminette
FLAGC		= -R CheckForbiddenSourceHeader
FLAGH		= -R CheckDefine

PATHLIBS	= libs/

PATHLIBFT	= ${PATHLIBS}libft/
LIBFTFLAG	= -lft
LIBFT		= -L ${PATHLIBFT}

PATHMLX		= ${PATHLIBS}minilibx-linux/
MLXFLAGS	= -lmlx -lXext -lX11
MLX			= -L ${PATHMLX}

LIBSFLAGS	= ${LIBFTFLAG} ${MLXFLAGS}

.c.o:
				@echo "${PREFIX}Compiling all ${GREEN}.c ${CYAN}files to ${GREEN}.o ${CYAN}..."
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
				${MAKE} ${PATHLIBFT}
				@echo "${PREFIX}Compiling ${GREEN}Minilibx ${CYAN}..."
				${MAKE} ${PATHMLX}
				@echo "${PREFIX}Compiling ${GREEN}FdF Program ${CYAN}..."
				${CC} ${OBJS} ${LIBFT} ${MLX} ${LIBSFLAGS} -o ${NAME}

clean:
				${MAKE} ${PATHLIBFT} clean
				@echo "${PREFIX}Cleaning ${GREEN}Minilibx ${CYAN}..."
				${MAKE} ${PATHMLX} clean
				@echo "${PREFIX}Removing ${GREEN}Objects ${CYAN}files ..."
				${RM} ${OBJS}

fclean:		clean
				${MAKE} ${PATHLIBFT} fclean
				@echo "${PREFIX}Removing ${GREEN}${NAME} program ${CYAN}..."
				${RM} ${NAME}

re:			fclean all

norminette:
				@echo "${PREFIX}Checking norminette for ${GREEN}.c ${CYAN}files ..."
				${NORM} ${FLAGC} ${SRCS}
				@echo "${PREFIX}Checking norminette for ${GREEN}.h ${CYAN}files ..."
				${NORM} ${FLAGH} ${HEADERS}

.PHONY:		all clean fclean re norminette
