# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/05 17:33:31 by wdebotte          #+#    #+#              #
#    Updated: 2022/01/11 11:24:14 by wdebotte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CYAN		= \033[0m\033[96m
GREEN		= \033[1m\033[92m

PREFIX		= \n${GREEN}=> ${CYAN}[${GREEN}Printf${CYAN}]

NAME		= libftprintf.a

SRCS		= srcs/ft_printf.c srcs/ft_printf_putnbr.c \
			srcs/ft_printf_strstuff.c

OBJS		= ${SRCS:.c=.o}

HEADER		= ft_printf.h

CC			= clang
CFLAGS		= -Wall -Wextra -Werror

RM			= rm -rf

NORM		= norminette
FLAGC		= -R CheckForbiddenSourceHeader
FLAGH		= -R CheckDefine

all:		strcompile ${NAME}

strcompile:
				@echo "${PREFIX} Compiling all ${GREEN}.c ${CYAN}to ${GREEN}.o ${CYAN}..."

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
				@echo "${PREFIX} Making ${GREEN}${NAME} ${CYAN}library ..."
				ar -rc ${NAME} ${OBJS}

clean:
			@echo "${PREFIX} Cleaning ${GREEN}Printf ${CYAN}..."
			${RM} ${OBJS}

fclean:		clean
				@echo "${PREFIX} Removing ${GREEN}${NAME} ${CYAN}library ..."
				${RM} ${NAME}

re:			fclean all

norminette:
				@echo "${PREFIX} Checking norminette for ${GREEN}.c ${CYAN}files ..."
				${NORM} ${FLAGC} ${SRCS}
				@echo "${PREFIX} Checking norminette for ${GREEN}.h ${CYAN}files ..."
				${NORM} ${FLAGH} ${HEADER}

.PHONY:		all clean fclean re norminette
