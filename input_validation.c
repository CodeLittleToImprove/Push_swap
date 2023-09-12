/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:05:36 by tbui-quo          #+#    #+#             */
/*   Updated: 2023/09/12 17:16:07 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_valid_input(char *argv[], size_t size)
{
	size_t	index;

	index = 0;

	if (is_not_a_duplicate(argv, size))
	{
		while (argv[index] != NULL)
		{
//			printf("entry checked %s\n", argv[index]);
			if (!is_valid_number(argv[index]))
			{
//				printf("hier wird verkackt %s\n", argv[index]);
				return (false);
			}

			index++;
		}
//		printf("input valid\n");
		return (true);
	}
	else
	{
//		printf("input invalid\n");
		return (false);
	}
}

bool	is_valid_start_character(char c)
{
	return (c == '+' || c == '-' || (c >= '0' && c <= '9'));
}

bool	is_valid_digit(char c)
{
	return (c >= '0' && c <= '9');
}
// maybe sign in separate function

bool	is_valid_number(char *str_nbr)
{
	if (!is_valid_start_character(*str_nbr))
		return (false);
	if ((*str_nbr == '+' || *str_nbr == '-') && !is_valid_digit(str_nbr[1]))
		return (false);
	while (*++str_nbr)
	{
		if (!is_valid_digit(*str_nbr))
			return (false);
	}
	return (true);
}

bool	is_not_a_duplicate(char *argv[], size_t size)
{
	size_t	outer_index;
	size_t	inner_index;
	size_t	max_int_len;

	outer_index = 0;
	max_int_len = 20;
	while (outer_index < size -1)
	{
		inner_index = outer_index + 1;
		while (inner_index < size)
		{
			if (ft_strncmp(argv[outer_index], argv[inner_index],
					max_int_len) == 0)
				return (false);
			inner_index++;
		}
		outer_index++;
	}
//printf("is not a duplicate\n");
	return (true);
}
