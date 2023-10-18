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

int	is_max(t_stack **stack_a)
{
	t_stack		*root;
	int			max;

	root = *stack_a;
	max = root->content;
	printf("max = %d\n", max);
	while (root->next)
	{
		root = root->next;
		if (root->content > max)
			max = root->content;
	}
	return (max);
}
// not tested
t_stack	*get_next_min(t_stack **stack)
{
	t_stack		*root;
	t_stack		*min;
	bool		has_min;

	root = *stack;
	min = NULL;
	has_min = false;
	if (root)
	{
		while (root)
		{
			if ((root->index = -1) && (!has_min) || root->content < min->content)
			{
				min = root;
				has_min = true;
			}
		root = root->next;
		}
	}
	return (min);
}

//not tested
void	index_stack(t_stack **stack)
{
	int			index;
	t_stack		*root;

	index = 0;
	root = get_next_min(*stack);
	while (root)
	{
		root->index = ++index;
		root = get_next_min(*stack);
	}
}

