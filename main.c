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

void	process_arguments(int argc, char *argv[], size_t *size, char ***input)
{
	if (argc <= 1)
	{
		*size = 0;
		*input = NULL;
		exit(0);
	}
	if (argc == 2)
	{
		*input = ft_split(argv[1], ' ');
		*size = argc;
	}
	else
	{
		*input = argv + 1;
		*size = argc - 1;
	}
}

int	main(int argc, char *argv[])
{
	t_stack_data_set	*set;
	size_t				size;
	char				**input;

	printf("argc = %d\n", argc);
	process_arguments(argc, argv, &size, &input);
	if (is_valid_input(input, size, argc) == true)
	{
		printf("valid input\n");
		set = init_stacks_struct();
		if (!set)
			return (1);
		set->stack_a = create_stack_a(input);
		if (!set->stack_a)
			return (1);
		if (argc == 2)
			ft_free_array(input);
		if (is_sorted(&set->stack_a) == true)
			return (stack_clear(&set->stack_a), free(set), 0);
		return (sort_check(&set->stack_a, &set->stack_b),
			stack_clear(&set->stack_a), free(set), 0);
	}
	else
	{
		printf("in else\n");
		return (write(STDERR_FILENO, "Error\n", 6), -1);
	}

}
