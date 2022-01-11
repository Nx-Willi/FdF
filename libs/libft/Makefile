# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 08:31:56 by wdebotte          #+#    #+#              #
#    Updated: 2022/01/11 11:21:31 by wdebotte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CYAN		= \033[0m\033[96m
GREEN		= \033[1m\033[92m

PREFIX		= \n${GREEN}=> ${CYAN}[${GREEN}Libft${CYAN}]

NAME		= libft.a

SRCS 		= srcs/str/ft_isalpha.c srcs/str/ft_isdigit.c srcs/str/ft_isalnum.c \
			srcs/str/ft_isascii.c srcs/str/ft_isprint.c srcs/str/ft_toupper.c \
			srcs/str/ft_tolower.c srcs/str/ft_strncmp.c srcs/str/ft_strdup.c \
			srcs/str/ft_strchr.c srcs/str/ft_strrchr.c srcs/str/ft_strnstr.c \
			srcs/str/ft_substr.c srcs/str/ft_strjoin.c srcs/str/ft_strtrim.c \
			srcs/str/ft_split.c srcs/str/ft_strmapi.c srcs/str/ft_strlen.c \
			srcs/str/ft_strlcpy.c srcs/str/ft_strlcat.c srcs/str/ft_striteri.c \
			srcs/str/ft_putchar.c srcs/str/ft_putstr.c \
			\
			srcs/mem/ft_memcmp.c srcs/mem/ft_bzero.c srcs/mem/ft_memset.c \
			srcs/mem/ft_memcpy.c srcs/mem/ft_memmove.c srcs/mem/ft_memchr.c \
			srcs/mem/ft_calloc.c \
			\
			srcs/file/ft_putchar_fd.c srcs/file/ft_putstr_fd.c \
			srcs/file/ft_putendl_fd.c srcs/file/ft_putnbr_fd.c \
			srcs/file/is_ext_correct.c \
			\
			srcs/lst/ft_lstsize.c srcs/lst/ft_lstadd_back.c \
			srcs/lst/ft_lstadd_front.c srcs/lst/ft_lstiter.c \
			srcs/lst/ft_lstdelone.c srcs/lst/ft_lstclear.c srcs/lst/ft_lstlast.c \
			srcs/lst/ft_lstnew.c srcs/lst/ft_lstmap.c \
			\
			srcs/othr/ft_atoi.c srcs/othr/ft_itoa.c \
			\
			srcs/get_next_line/get_next_line.c srcs/get_next_line/get_next_line_utils.c

OBJS		= ${SRCS:.c=.o}

HEADERS		= headers/get_next_line.h headers/libft.h

CC			= clang
CFLAGS		= -Wall -Wextra -Werror

RM			= rm -rf

NORM		= norminette
FLAGC		= -R CheckForbiddenSourceHeader
FLAGH		= -R CheckDefine

MAKE		= make -C

PATHLIBS	= libs/

PATHPRINTF	= ${PATHLIBS}ft_printf/
PRINTFLIB	= ${PATHPRINTF}libftprintf.a

all:		strcompile ${NAME} norminette

strcompile:
				@echo "${PREFIX} Compiling all ${GREEN}.c ${CYAN}to ${GREEN}.o ${CYAN}..."

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
				@echo "${PREFIX} Calling ${GREEN}Printf ${CYAN}library ..."
				${MAKE} ${PATHPRINTF}
				@echo "${PREFIX} Making ${GREEN}${NAME} ${CYAN}library ..."
				ar -rc ${NAME} ${PRINTFLIB} ${OBJS}

clean:
				@echo "${PREFIX} Calling ${GREEN}Printf ${CYAN}clean ..."
				${MAKE} ${PATHPRINTF} clean
				@echo "${PREFIX} Cleaning ${GREEN}Libft ${CYAN}..."
				${RM} ${OBJS}

fclean:		clean
				@echo "${PREFIX} Calling ${GREEN}Printf ${CYAN}fclean ..."
				${MAKE} ${PATHPRINTF} fclean
				@echo "${PREFIX} Removing ${GREEN}${NAME} ${CYAN}library ..."
				${RM} ${NAME}

re:			fclean all

norminette:
				@echo "${PREFIX} Calling ${GREEN}Printf ${CYAN}norminette ..."
				${MAKE} ${PATHPRINTF} norminette
				@echo "${PREFIX} Checking norminette for ${GREEN}.c ${CYAN}files ..."
				${NORM} ${FLAGC} ${SRCS}
				${COLORRESET}
				@echo "${PREFIX} Checking norminette for ${GREEN}.h ${CYAN}files ..."
				${NORM} ${FLAGH} ${HEADERS}

.PHONY:		all clean fclean re norminette
