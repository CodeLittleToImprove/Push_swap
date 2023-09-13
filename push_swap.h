/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:44:37 by tbui-quo          #+#    #+#             */
/*   Updated: 2023/08/22 15:59:19 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <ctype.h>
# include <string.h>
# include <limits.h>

typedef struct s_stack
{
	int							*content;
	struct s_stack				*next;
//	struct s_stack			*prev;
}	t_stack;

typedef struct s_stack_data_set
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_stack_data_set;

//input_validation
bool				is_valid_input(char *argv[], size_t size);
bool				is_valid_start_character(char c);
bool				is_valid_digit(char c);
bool				is_valid_number(char *str_nbr);
bool				is_valid_int_string(char *str_nbr);
bool				is_array_not_a_duplicate(char *argv[], size_t size);

//error handling
void				ft_free_array(char *array[]);

//stack_initialization
t_stack_data_set		*init_stacks_struct(void);
t_stack				*init_stack_a(char *argv[]);
t_stack				*create_list(char **input_array);
void				insert_stack(t_stack **root, int value);

//utils.c
long long	ft_atoll(const char *nptr);

//test utils
void				print_stack(t_stack *stack);
#endif