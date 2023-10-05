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
	free(temp->content);
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

bool	is_sorted(t_stack **lst)
{
	t_stack	*current;
	int	*num1;
	int *num2;

	current = *lst;
	while (current->next)
	{
		num1 = (int *)(current->content);
		num2 = (int *)(current->next->content);
		if (num1 > num2)
			return (false);
		current = current->next;
	}
	return (true);
}
