/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:39:15 by tbui-quo          #+#    #+#             */
/*   Updated: 2023/08/23 17:39:15 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_stack(t_stack **root, int value)
{
	t_stack	*new_node;
	t_stack	*current;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		exit(1);
	new_node->content = malloc(sizeof(int));
	if (new_node->content == NULL)
	{
		free(new_node);
		exit(1);
	}
	*(new_node->content) = value;
	new_node->next = NULL;

	if (*root == NULL)
	{
		*root = new_node;
		return ;
	}
	current = *root;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
}

//size_t	init_stack_a(t_stack **a, char *argv[], int argc)
//{
//	size_t	argv_index;
//
//	argv_index = 1;
//
//	while
//}

t_stack_data	*init_stacks_struct(void)
{
	// not working
	t_stack_data	*set;

	set = malloc(sizeof(t_stack_data));
	if (!set)
		return (NULL);
	set->stack_a = NULL;
	set->stack_b = NULL;
	return (set);
}
// not working

t_stack	*init_stack_a(char *argv[], int argc)
{
	t_stack		*stack_a;
	char		**input_array;

	input_array = argv + 1;

//	while (argv_index < argc)
//	{
//		stack_a = insert_stack(&stack_a, ft_atoi(argv[argv_index]));
//	}

	stack_a = create_list(input_array, argc);
	return (stack_a);
}
// not working

t_stack	*create_list(char **input_array, int argc)
{
	size_t			index;
	t_stack			*stack_a;

	index = 1;

	while (index < argc)
	{
		insert_stack(&stack_a, ft_atoi(input_array[index]));
		index++;
	}

	return (stack_a);
}
//int	main(void)
//{
//	t_stack	*root;
//	t_stack	*current;
//
//	root = NULL;
//
//	insert_stack(&root, 5);
//	insert_stack(&root, -2);
//	insert_stack(&root, 6);
//
//	current = root;
//	while (current != NULL)
//	{
//		if (current->content != NULL)
//			printf("%d\n", *(current->content));
//		else
//			printf("Content is NULL \n");
//		current = current->next;
//	}
//
//	return (0);
//}
