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
	t_stack_node	*a;
	t_stack_node	*b;

	if (argc <= 1)
		return (1);
//	printf("%d\n", argc - 1);

	if (is_valid_input(argv, argc - 1) == true)
	{
//		if (argc == 2)
//			argv = ft_split(argv[1], ' ');
//	stack_init
		printf("input valid");
	}
	else
	{
//		ft_free_array(argv);
		printf("input invalid!");
	}

	return (0);
}
