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

void	rotate(t_stack **stack_x)
{
	t_stack	*first_element;
	t_stack	*second_element;
	t_stack	*new_first_element;

	if (*stack_x == NULL || (*stack_x)->next == NULL)
		return ;
	first_element = *stack_x;
	second_element = first_element->next;
	new_first_element = second_element;
	first_element->next = NULL;
	while (second_element->next != NULL)
		second_element = second_element->next;
	second_element->next = first_element;
	*stack_x = new_first_element;
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", STDOUT_FILENO);
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", STDOUT_FILENO);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", STDOUT_FILENO);
}
