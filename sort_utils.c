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

void	sort_check(t_stack **stack_a, t_stack **stack_b)
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
	return (max);
}

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
	return (min->index);
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
