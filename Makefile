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

SRCS			= main.c input_validation.c error_handler.c stack_init.c test_utils.c utils.c linked_list_utils.c push_command.c swap_command.c rotate_command.c reverse_rotate_command.c sort_utils.c radix_sort.c

OBJS			= ${SRCS:.c=.o}

HEADER			= push_swap.h


# Compiler and compilation flags

CC				= cc

CFLAGS			= -Wall -Wextra -Werror

debug: CFLAGS += -g
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



debug: all
clean:
				${RM} ${OBJS}
				make clean -C ${LIBFT}

fclean:			clean
				${RM} ${NAME}
				make fclean -C ${LIBFT}

re:				fclean all

.PHONY: all lib clean fclean re