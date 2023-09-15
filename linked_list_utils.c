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
