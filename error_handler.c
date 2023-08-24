/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:05:18 by tbui-quo          #+#    #+#             */
/*   Updated: 2023/08/23 16:05:18 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_array(char *array[])
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_free_linked_list(t_stack_node *root)
{
	t_stack_node	*current;
	t_stack_node	*temp;

	current = root;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp->content);
		free(temp);
	}
}
