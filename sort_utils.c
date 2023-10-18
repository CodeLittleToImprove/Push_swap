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
void	sort2(t_stack **stack_a, int stack_len)
{
	t_stack	*first_element;
	t_stack	*second_element;

	if (stack_len != 2)
		return;
	first_element = *stack_a;
	second_element = first_element->next;
	if (first_element->content > second_element->content)
		sa(stack_a);
}

void	sort3(t_stack **stack_a, int stack_len)
{
	int		max;

	if (stack_len != 3)
		return;
	max = is_max(&*stack_a);
	if (max == (*stack_a)->content )
	{
//		printf("run ra \n");
		ra(&*stack_a);
	}

	if (max == (*stack_a)->next->content)
	{
//		printf("run rra \n");
		rra(&*stack_a);
	}
	if ((*stack_a)->content > (*stack_a)->next->content)
	{
//		printf("run sa \n");
		sa(&*stack_a);
	}

}
// implement sort stuff
void sort_check(t_stack **stack_a, t_stack **stack_b)
{
	int stack_len;
	stack_len = lst_len(stack_a);
	if (stack_len == 2)
	{
		printf("sort2 start\n");
		sort2(stack_a, stack_len);
		printf("sort2 successful\n");
	}
	else if (stack_len == 3)
	{
		printf("sort3 start\n");
		sort3(stack_a, stack_len);
		printf("sort3 successful\n");
	}

	else
	{
		printf("should use radix\n");
	}


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
}