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
	{
		perror("Error allocating memory for new node");
		exit(1);
	}
//	printf("Allocated memory for new node at address: %p\n", (void *)new_node);
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
//		printf("Should happen only once \n");
		*root = new_node;
		return ;
	}
//	printf("current pointer value before setting root: %p\n", (void *)current);
	current = *root;
//	printf("current pointer value after setting root: %p\n", (void *)current);
	if (current == NULL)
	{
//		printf("I am hopefully not here");
		perror("Error: Attempted to insert into an empty stack");
		exit(1);
	}
//	if (current->next == NULL)
	printf("Traversing the list:\n");
	while (current->next != NULL)
	{
		printf("current pointer value before setting next: %p\n", (void *)current);
		current = current->next;
		printf("current pointer value after setting next: %p\n", (void *)current);
	}
	printf("Adding new node at the end:\n");
	current->next = new_node;
}


t_stack_data_set	*init_stacks_struct(void)
{
	t_stack_data_set	*set;

	set = malloc(sizeof(t_stack_data_set));
	if (!set)
		return (NULL);
	set->stack_a = NULL;
	set->stack_b = NULL;
	return (set);
}


t_stack	*init_stack_a(char *argv[])
{
	t_stack		*stack_a;
	char		**input_array;


	input_array = argv;

	stack_a = create_list(input_array);

	return (stack_a);
}


t_stack	*create_list(char **input_array)
{
	size_t			index;
	t_stack			*stack_a;

	stack_a = NULL;

	index = 0;
//	printf("currently insert value %s\n", input_array[0]);
//	printf("currently insert value %s\n", input_array[1]);
//	printf("currently insert value %s\n", input_array[2]);
//	printf("argc %d\n", argc);
	while (input_array[index])
	{
		printf("Inserting element %d\n", ft_atoi(input_array[index]));
		insert_stack(&stack_a, ft_atoi(input_array[index]));
		if (!stack_a)
			return (NULL);
//		printf("index pre incrementation %zu\n", index);
		index++;
//		printf("index after incrementation %zu\n", index);
	}
	return (stack_a);
}
//int	old main(void)
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
