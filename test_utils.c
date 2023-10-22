/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:49:55 by tbui-quo          #+#    #+#             */
/*   Updated: 2023/08/31 16:55:39 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack		*current;
	size_t		index;

	current = stack;
	index = 0;

	if (current == NULL)
		printf("current is null\n");

	while (current != NULL)
	{
		printf("Element[%zu] is %d\n", index, current->content);
		current = current->next;
		index++;
	}
}

void	print_index(t_stack *stack)
{
	t_stack		*current;
	size_t		index;

	current = stack;
	index = 0;

	if (current == NULL)
		printf("current is null\n");

	while (current != NULL)
	{
		printf("Element[%zu] is %d\n", index, current->index);
		current = current->next;
		index++;
	}
}
