# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/08 18:23:13 by wdebotte          #+#    #+#              #
#    Updated: 2022/01/10 21:36:42 by wdebotte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CYAN		= \033[0m\033[96m
GREEN		= \033[1m\033[92m
NORMAL		= \033[0m

PREFIX		= \n${GREEN}=> ${CYAN}[${GREEN}FdF${CYAN}] 

NAME		= fdf

SRCS		= ./srcs/fdf.c

HEADERS		= ./headers/fdf.h ./headers/fdf_structures.h

OBJS		= ${SRCS:.c=.o}

CC			= clang
CFLAGS		= -Wall -Wextra -Werror

RM			= rm -rf
MAKE		= make -C

NORM		= norminette
FLAGC		= -R CheckForbiddenSourceHeader
FLAGH		= -R CheckDefine

PATHLIBS	= ./libs/

PATHLIBFT	= ${PATHLIBS}libft/
LIBFTFLAG	= -lft
LIBFT		= -L${PATHLIBFT}

PATHPRINTF	= ${PATHLIBS}ft_printf/
PRINTFFLAG	= -lftprintf
PRINTF		= -L${PATHPRINTF}

PATHMLX		= ${PATHLIBS}minilibx-linux/
MLXFLAGS	= -lmlx -lXext -lX11
MLX			= -L${PATHMLX}

LIBSFLAGS	= ${LIBFTFLAG} ${PRINTFFLAG} ${MLXFLAGS}

.c.o:
				@echo "${PREFIX}Compiling all ${GREEN}.c ${CYAN}files to ${GREEN}.o ${CYAN}..."
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
				@echo "${NORMAL}"

${NAME}:	${OBJS}
				@echo "${PREFIX}Compiling ${GREEN}Libft ${CYAN}..."
				${MAKE} ${PATHLIBFT}
				@echo "${PREFIX}Compiling ${GREEN}Printf ${CYAN}..."
				${MAKE} ${PATHPRINTF}
				@echo "${PREFIX}Compiling ${GREEN}Minilibx ${CYAN}..."
				${MAKE} ${PATHMLX}
				@echo "${PREFIX}Compiling ${GREEN}FdF Program ${CYAN}..."
				${CC} ${LIBFT} ${PRINTF} ${MLX} ${OBJS} ${LIBSFLAGS} -o ${NAME}
				@echo "${NORMAL}"

all:		${NAME} norminette

clean:
				@echo "${PREFIX}Cleaning ${GREEN}Libft ${CYAN}..."
				${MAKE} ${PATHLIBFT} clean
				@echo "${PREFIX}Cleaning ${GREEN}Printf ${CYAN}..."
				${MAKE} ${PATHPRINTF} clean
				@echo "${PREFIX}Cleaning ${GREEN}Minilibx ${CYAN}..."
				${MAKE} ${PATHMLX} clean
				@echo "${PREFIX}Removing ${GREEN}Objects ${CYAN}files ..."
				${RM} ${OBJS}
				@echo "${NORMAL}"

fclean:		clean
				@echo "${PREFIX}Fcleaning ${GREEN}Libft ${CYAN}..."
				${MAKE} ${PATHLIBFT} fclean
				@echo "${PREFIX}Fcleaning ${GREEN}Printf ${CYAN}..."
				${MAKE} ${PATHPRINTF} fclean
				@echo "${PREFIX}Removing ${GREEN}${NAME} program ${CYAN}..."
				${RM} ${NAME}
				@echo "${NORMAL}"

re:			fclean all

norminette:
				@echo "${PREFIX}Checking norminette for ${GREEN}.c ${CYAN}files ..."
				${NORM} ${FLAGC} ${SRCS}
				@echo "${PREFIX}Checking norminette for ${GREEN}.h ${CYAN}files ..."
				${NORM} ${FLAGH} ${HEADERS}
				@echo "${NORMAL}"

.PHONY:		all clean fclean re norminette
