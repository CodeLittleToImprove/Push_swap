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
// need to learn how to read linked list better and let chat gpt explain me this
void	insert_stack(t_stack_node **root, int value)
{
	t_stack_node	*new_node;
	t_stack_node	*current;

	new_node = malloc(sizeof(t_stack_node));
	if (new_node == NULL)
		exit(1);
	new_node->next = NULL;
	new_node->content = value;

	current = *root;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
}

//int main (void)
//{
//	t_stack_node *root = malloc(sizeof(t_stack_node));
//	root->next = NULL;
//	root->content = 5;
//
//	insert_stack(&root, -2);
//	insert_stack(&root, 6);
//
//	for (t_stack_node *current = root; current != NULL; current = current ->next)
//		printf("%d\n", current->content);
//}