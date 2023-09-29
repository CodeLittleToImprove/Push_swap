/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 20:25:37 by tbui-quo          #+#    #+#             */
/*   Updated: 2023/09/29 20:25:37 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:50:37 by tbui-quo          #+#    #+#             */
/*   Updated: 2023/09/29 13:50:37 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack_x)
{
	t_stack	*first_element;
	t_stack *second_last_element;
	t_stack *current_element;

	if (*stack_x == NULL || (*stack_x)->next == NULL)
		return;
	first_element = *stack_x;
	current_element = first_element;
	while (current_element->next != NULL)
	{
		second_last_element = current_element;
		current_element = current_element->next;
	}
	second_last_element->next = NULL;
	current_element->next = first_element;
	*stack_x = current_element;
}

void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}