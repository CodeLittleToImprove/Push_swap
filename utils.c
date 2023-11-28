/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:21:34 by tbui-quo          #+#    #+#             */
/*   Updated: 2023/09/13 19:21:34 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoll(const char *nbr_str)
{
	long long	nbr;
	int			sign;

	nbr = 0;
	sign = 1;
	while (*nbr_str == ' ' || (*nbr_str >= '\t' && *nbr_str <= '\r'))
		nbr_str++;
	if (*nbr_str == '-')
		sign = -1;
	if (*nbr_str == '+' || *nbr_str == '-')
		nbr_str++;
	while (*nbr_str >= '0' && *nbr_str <= '9')
	{
		if ((nbr > LLONG_MAX / 10) || (nbr == LLONG_MAX / 10
				&& (*nbr_str - '0') > LLONG_MAX % 10))
		{
			if (sign == -1)
				return (LLONG_MIN);
			else
				return (LLONG_MAX);
		}
		nbr = nbr * 10 + *nbr_str - '0';
		nbr_str++;
	}
	return (sign * nbr);
}
