/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:59:06 by tbui-quo          #+#    #+#             */
/*   Updated: 2023/09/15 18:00:47 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_node_delete(t_stack **lst)
{
	t_stack	*temp;

	if (*lst == NULL)
		return ;
	temp = *lst;
	*lst = (*lst)->next;
	free(temp);
}

void	stack_clear(t_stack **stack)
{
	while (*stack != NULL)
	{
		stack_node_delete(stack);
	}
	stack = NULL;
}

int	lst_len(t_stack **lst)
{
	t_stack	*current;
	int		lst_len;

	lst_len = 0;
	current = *lst;
	if (lst == NULL)
		return (-1);
	while (current != NULL)
	{
		current = current->next;
		lst_len++;
	}
	return (lst_len);
}

int	get_max_num(t_stack *stack_a)
{
	t_stack		*current;
	int			max;

	current = stack_a;
	max = current->content;
	while (current->next)
	{
		current = current->next;
		if (current->content > max)
			max = current->content;
	}
//	printf("max = %d\n", max);
	return (max);
}
// does this always return 1?
int	find_minimum_index(t_stack *stack_a)
{
	t_stack		*current;
	t_stack		*min;

	current = stack_a;
	min = current;
	while (current->next)
	{
		current = current->next;
		if (current->content < min->content)
			min = current;
	}
//	printf("min = %d\n", min->index);
	return (min->index);
}
t_stack	*get_next_min_node(t_stack *stack)
{
	t_stack		*root;
	t_stack		*min;
	bool		has_min;

	root = stack;
	min = NULL;
	has_min = false;
	if (root)
	{
		while (root)
		{
			if ((root->index == -1) && ((!has_min)
					|| (root->content < min->content)))
			{
				min = root;
				has_min = true;
			}
		root = root->next;
		}
	}
	return (min);
}

int	get_distance(t_stack *stack, int index)
{
	t_stack	*current;
	int		distance;

	current = stack;
	distance = 0;
	while (current)
	{
		if (current->index == index)
			break ;
		distance++;
		current = current->next;
	}
	return (distance);
}


