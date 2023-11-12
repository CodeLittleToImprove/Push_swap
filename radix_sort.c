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

//int					get_max_bits(t_stack **stack)
//{
//	t_stack	*current;
//	int		max;
//	int		max_bits;
//
//	current = *stack;
//	max = current->index;
//	max_bits = 0;
//
//	while(current)
//	{
//		if (current->index > max)
//			max = current->index;
//		current = current->next;
//	}
//	while ((max >> max_bits) != 0)
//		++max_bits;
//	return (max_bits);
//}
// some error here
//void	radix_sort(t_stack **stack_a, t_stack **stack_b)
//{
//	int	stack_len;
//	int	max_bits;
//	int	outer_index;
//	int	inner_index;
//	int nbr;
//
//	outer_index = 0;
//	stack_len = lst_len(stack_a);
////	printf("stacklen = %d\n",stack_len);
//	max_bits = get_max_bits(stack_a);
////	printf("max_bits in radix sort = %d\n",max_bits);
//	while (outer_index < max_bits)
//	{
//		inner_index = 0;
//		while(inner_index++ <= stack_len)
//		{
//			nbr = (*stack_a)->content;
////			printf("nbr = %d\n",nbr);
//			//some error below here
////			if (((*stack_a)->index >> outer_index) & 1)
//			if (((nbr >> outer_index) & 1) == 1)
//				ra(&*stack_a);
//			else
//			{
////				printf("in else\n");
////				printf("start print stack a\n");
////				print_stack(*stack_a);
////				printf("done printing a\n");
////				printf("stack b before pb\n");
////				print_stack(*stack_b);
//
//				pb(&*stack_b, &*stack_a);
//				printf("stack b after pb\n");
//				print_stack(*stack_b);
//			}
//			printf("after else\n");
//			while (*stack_b != NULL)
//				pa(&*stack_a, &*stack_b);
//		outer_index++;
//		}
//	}
//}
void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_len;
	int	bit_number;
	int	index;
	int	nbr;

	stack_len = lst_len(stack_a);
	bit_number = 0;
	index = 0;
	while (is_sorted(&*stack_a) != true)
	{
		while (index < stack_len)
		{
			nbr = (*stack_a)->content;
			if (((nbr >> bit_number) & 1) == 1)
				ra(&*stack_a);
			else
			{
				pb(&*stack_b, &*stack_a);
				print_stack(&stack_b);
			}
			index++;
		}
		// breaks here for negative numbers
		while (*stack_b)
			pa(&*stack_a, &*stack_b);
		bit_number++;
		index = 0;
	}
}