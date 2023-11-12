/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:44:17 by tbui-quo          #+#    #+#             */
/*   Updated: 2023/07/04 18:07:18 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// check how many steps averages I need
int	main(int argc, char *argv[])
{
	t_stack_data_set	*set;
	size_t				size;
//	printf("argc = %d\n", argc);
	if (argc <= 1)
		return (1);

	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv = argv + 1;
	size = argc - 1;


	if (is_valid_input(argv, size) == true)
	{
		set = init_stacks_struct();
		if (!set)
			return (1);
		set->stack_a = init_stack_a(argv);
		if (argc == 2)
			ft_free_array(argv);
		if (is_sorted(&set->stack_a) == true)
		{
			printf("all numbers are already sorted\n");
			return (0);
		}
		printf("Nodes successful written\n");
//		stack_clear(&set);
//		if (set == NULL) {
//			printf("The linked list has been cleared and is now empty.\n");
//		} else {
//			printf("The linked list still contains elements.\n");
//		}

//		print_stack(set->stack_a);
//		swap(&set->stack_a);
//		printf("swap done\n");
//		print_stack(set->stack_a);

//		print_stack(set->stack_a);
//		printf("finished print stack_a\n");
		print_stack(set->stack_a);
		printf("before_sort_check\n");
		sort_check(&set->stack_a, &set->stack_b);
		printf("after_sorted\n");
		print_stack(set->stack_a);
		printf("finished print stack_a\n");
		print_stack(set->stack_b);
		stack_clear(&set->stack_a);
	}
	else
	{
		printf("else case in main \n");
//		ft_free_array(argv);
		return (write(STDERR_FILENO, "Error\n", 6));
	}
	free(set);
	return (0);
}
