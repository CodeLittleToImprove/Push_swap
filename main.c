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
	t_stack_data	*set;

	if (argc <= 1)
		return (1);


	if (is_valid_input(argv, argc - 1) == true)
	{
//		if (argc == 2)
//			argv = ft_split(argv[1], ' ');
		set = init_stacks_struct();
		if (!set)
			return (1);
		set->stack_a = init_stack_a(argv, argc);

		while (argv_index < argc)
		{
			insert_stack(&a, ft_atoi(argv[argv_index]));
			argv_index++;
		}
		printf("Nodes written\n");
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
	}
	else
	{

//		ft_free_array(argv);

	}

	return (0);
}
