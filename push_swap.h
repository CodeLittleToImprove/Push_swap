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

typedef struct s_stack_node
{
	int							*content;
	struct s_stack_node			*next;
//	struct s_stack_node			*prev;
}	t_stack_node;

//input_validation
bool	is_valid_input(char *argv[], int size);
bool	is_valid_start_character(char c);
bool	is_valid_digit(char c);
bool	is_valid_number(char *str_nbr);
bool	is_not_a_duplicate(char *argv[], int size);

//error handling
void	ft_free_array(char *array[]);

//stack_initialization
void	insert_stack(t_stack_node **root, int value);
#endif