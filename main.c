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
// not working
int	main(int argc, char *argv[])
{
	t_stack_data_set	*set;
	size_t			size;
//	char			**cleaned_input;

// implement operations
	printf("argc = %d\n", argc);
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
		printf("Nodes successful written\n");
		// test if node are written correct
//		test = a;
//		while (test != NULL)
//		{
//			printf("Start print\n");
//			if (test->content != NULL)
//				printf("%d\n", *(test->content));
//			else
//				printf("Content is NULL \n");
//			test = test->next;
//		}
		print_stack(set->stack_a);
	}
	else
	{
		printf("else case in main \n");
//		ft_free_array(argv);
		return (write(STDERR_FILENO, "Error\n", 6));
	}

	return (0);
}
