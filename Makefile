# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 15:08:12 by tbui-quo          #+#    #+#              #
#    Updated: 2023/05/31 15:02:08 by tbui-quo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target names

NAME			= push_swap

LIBFT			= libft


# Directories and source files

SRCDIR			= srcs

SRCS			= main.c input_validation.c

OBJS			= ${SRCS:.c=.o}

HEADER			= push_swap.h


# Compiler and compilation flags

CC				= cc

CFLAGS			= -Wall -Wextra -Werror


# Commands

RM				= rm -f

all:			lib ${NAME}

${NAME}:		${OBJS} ${LIBFT}/libft.a
				${CC} ${CFLAGS} ${OBJS} -L ${LIBFT} -lft -o ${NAME}

${OBJS}:		${HEADER}

lib:
				make -C ${LIBFT}

run:			all
				./$(NAME)


clean:
				${RM} ${OBJS}
				make clean -C ${LIBFT}

fclean:			clean
				${RM} ${NAME}
				make fclean -C ${LIBFT}

re:				fclean all

.PHONY: all lib clean fclean re