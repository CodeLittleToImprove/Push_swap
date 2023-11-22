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

t_stack	*create_stack_a(char *argv[])
{
	t_stack		*stack_a;
	char		**input_array;
	size_t		index;

	stack_a = NULL;
	input_array = argv;
	index = 0;
	while (input_array[index])
	{
		printf("Inserting element %d\n", ft_atoi(input_array[index]));
		if (insert_stack(&stack_a, ft_atoi(input_array[index])) == false)
		{
			stack_clear(&stack_a);
			return (NULL);
		}
		index++;
	}
	index_stack(&stack_a);
	return (stack_a);
}

bool	insert_stack(t_stack **root, int value)
{
	t_stack	*current;
	t_stack	*new_node;

	current = NULL;
	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
	{
		return (false);
	}
	new_node->content = value;
	new_node->index = -1;
	new_node->next = NULL;
	if (*root == NULL)
		*root = new_node;
	else
	{
		current = *root;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
	return (true);
}

void	index_stack(t_stack **stack)
{
	int			index;
	t_stack		*root;

	index = 0;
	root = get_next_min_node(*stack);
	while (root)
	{
		root->index = ++index;
		root = get_next_min_node(*stack);
	}
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
