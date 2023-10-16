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
	int	num1;
	int num2;

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

// implement sort stuff
//void sort_check(t_stack **stack_a, t_stack **stack_b)
//{
//	size_t stack_len;
//	stack_len = lst_len(stack_a);
//	if (stack_len == 2)
//		sort2(stack_a);
//	else if (stack_len == 3)
//		sort3(stack_a);
//	else if (stack_len == 4)
//	{
//		sort4(stack_a, stack_b);
//	}
//	else if (stack_len == 5)
//	{
//		sort5(stack_a, stack_b);
//	}
//	else
//	{
//		radix_sort(stack_a, stack_b);
//	}
//}