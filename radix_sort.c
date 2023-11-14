/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:21:37 by tbui-quo          #+#    #+#             */
/*   Updated: 2023/11/04 20:21:37 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_len;
	int	bit_number;
	int	index;
	int	current_index;

	stack_len = lst_len(stack_a);
	bit_number = 0;
	index = 0;
	while (is_sorted(&*stack_a) != true)
	{
		while (index < stack_len)
		{
			current_index = (*stack_a)->index;
			if (((current_index >> bit_number) & 1) == 1)
				ra(&*stack_a);
			else
				pb(&*stack_b, &*stack_a);
			index++;
		}
		while (*stack_b)
			pa(&*stack_a, &*stack_b);
		bit_number++;
		index = 0;
	}
}
