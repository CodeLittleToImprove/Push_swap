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

long long	ft_atoll(const char *nptr)
{
    long long		nbr;
    int		sign;

    nbr = 0;
    sign = 1;
    while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
        nptr++;
    if (*nptr == '-')
        sign = -1;
    if (*nptr == '+' || *nptr == '-')
        nptr++;
    while (*nptr >= '0' && *nptr <= '9')
    {
        if ((nbr > LLONG_MAX / 10) || (nbr == LLONG_MAX / 10 && (*nptr - '0') > LLONG_MAX % 10))
        {
            if (sign == -1)
                return (LLONG_MIN);
            else
                return (LLONG_MAX);
        }
        nbr = nbr * 10 + *nptr - '0';
        nptr++;
    }
    return (sign * nbr);
}