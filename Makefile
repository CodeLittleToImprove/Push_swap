# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/08 17:37:51 by tbui-quo          #+#    #+#              #
#    Updated: 2023/12/08 17:37:51 by tbui-quo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
debug: CFLAGS += -g

SRC = main.c \
input_validation.c \
array_cleanup.c \
stack_init.c \
test_utils.c \
utils.c \
linked_list_utils.c \
push_command.c \
swap_command.c \
rotate_command.c \
reverse_rotate_command.c \
sort_utils.c \
sort_up_to_five.c \
radix_sort.c

OBJ = $(SRC:.c=.o)

LIBS = -Llib/libft -lft -Llib/ft_printf -lftprintf

all: $(NAME)

$(NAME): $(OBJ)
	@make -C lib/libft
	@make -C lib/ft_printf
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C lib/libft
	@make clean -C lib/ft_printf
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C lib/libft
	@make fclean -C lib/ft_printf
	@rm -f $(NAME)

re: fclean all

debug: all

.PHONY: all clean fclean re