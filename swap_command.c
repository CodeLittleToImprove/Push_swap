/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 22:27:42 by tbui-quo          #+#    #+#             */
/*   Updated: 2023/09/26 22:27:42 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack_x)
{
	t_stack	*first_element;
	t_stack	*second_element;

	first_element = NULL;
	second_element = NULL;
	if (*stack_x == NULL || (*stack_x)->next == NULL)
		return;
	first_element = (*stack_x);
	second_element = (*stack_x) ->next;
	first_element->next = second_element ->next;
	second_element->next = first_element;
	*stack_x = second_element;

}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}