/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:31:50 by tbui-quo          #+#    #+#             */
/*   Updated: 2023/10/13 21:31:50 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack **lst)
{
	t_stack	*current;
	int		num1;
	int		num2;

	current = *lst;
	while (current->next)
	{
		num1 = (current->content);
		num2 = (current->next->content);
		if (num1 > num2)
			return (false);
		current = current->next;
	}
	return (true);
}

void	sort2(t_stack **stack_a)
{
	t_stack	*first_element;
	t_stack	*second_element;

	first_element = *stack_a;
	second_element = first_element->next;
	if (first_element->content > second_element->content)
		sa(stack_a);
}

void	sort3(t_stack **stack_a)
{
	int		max;

	max = get_max_num(*stack_a);
	if (max == (*stack_a)->content)
	{
		ra(&*stack_a);
	}
	if (max == (*stack_a)->next->content)
	{
		rra(&*stack_a);
	}
	if ((*stack_a)->content > (*stack_a)->next->content)
	{
		sa(&*stack_a);
	}
}

void	sort4(t_stack **stack_a, t_stack **stack_b)
{
	int	distance_to_lowest_index;

	distance_to_lowest_index = get_distance(*stack_a, find_minimum_index(*stack_a));
	if (distance_to_lowest_index == 1)
		ra(&*stack_a);

	else if (distance_to_lowest_index == 2)
	{
		ra(&*stack_a);
		ra(&*stack_a);
	}
	else if (distance_to_lowest_index == 3)
		rra(&*stack_a);

	if (is_sorted(&*stack_a))
		return ;
	pb(&*stack_b, &*stack_a);
	sort3(stack_a);
	pa(&*stack_a, &*stack_b);
}

void	sort5(t_stack **stack_a, t_stack **stack_b)
{
	int	distance_to_lowest_index;

	distance_to_lowest_index = get_distance(*stack_a, find_minimum_index(*stack_a));
	if (distance_to_lowest_index == 1)
		ra(&*stack_a);
	else if (distance_to_lowest_index == 2)
	{
		ra(&*stack_a);
		ra(&*stack_a);
	}
	else if (distance_to_lowest_index == 3)
	{
		rra(&*stack_a);
		rra(&*stack_a);
	}
	else if (distance_to_lowest_index == 4)
		rra(&*stack_a);
	if (is_sorted(&*stack_a))
		return ;
	pb(&*stack_b, &*stack_a);
	sort4(stack_a, stack_b);
	pa(&*stack_a, &*stack_b);
}

void sort_check(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_len;

	stack_len = lst_len(stack_a);
	if (stack_len == 2)
		sort2(stack_a);
	else if (stack_len == 3)
		sort3(stack_a);
	else if (stack_len == 4)
		sort4(stack_a, stack_b);
	else if (stack_len == 5)
		sort5(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}
