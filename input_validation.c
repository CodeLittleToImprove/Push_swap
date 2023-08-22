/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:05:36 by tbui-quo          #+#    #+#             */
/*   Updated: 2023/08/22 15:51:59 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_valid_input(char *argv[])
{
	size_t	index;

	index = 1;
	while (*argv[index] != '\0')
	{
		if (is_a_number(argv[index]) == false)
			return (false);
		index++;
	}

	return (true);
}

bool	is_a_number(char *argv)
{
	if (argv == NULL || *argv == '\0')
		return (false);

	while (*argv)
	{
		if (!isdigit(*argv) && *argv != '-')
			return (false);
		argv++;
	}

	return true;
}

//bool	is_not_a_duplicate(char *argv[])
//{
//	return (true);
//}
