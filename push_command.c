/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:17:33 by tbui-quo          #+#    #+#             */
/*   Updated: 2023/09/22 20:17:33 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **dest, t_stack **src)
{
	t_stack *node_to_push;

	if (*src == NULL)
		return;
	node_to_push = *src;
	*src = (*src)->next;
	if (*dest == NULL) {
		*dest = node_to_push;
		node_to_push->next = NULL;
	} else
	{
		node_to_push->next = *dest;
	}
}
	void	pa(t_stack **a, t_stack **b)
	{
		push(a, b);
	}

	void	pb(t_stack **b, t_stack **a)
	{
		push(b, a);
	}