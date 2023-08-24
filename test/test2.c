# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <ctype.h>
# include <string.h>


typedef struct s_stack_node
{
	int							*content;
	struct s_stack_node			*next;
	struct s_stack_node			*prev;
}	t_stack_node;

void	insert_stack(t_stack_node **root, int value)
{
	t_stack_node	*new_node;
	t_stack_node	*current;

	new_node = malloc(sizeof(t_stack_node));
	if (new_node == NULL)
		exit(1);
	new_node->content = malloc(sizeof(int));
	if (new_node->content == NULL)
	{
		free(new_node);
		exit(1);
	}
	*(new_node->content) = value;
	new_node->next = NULL;

	if (*root == NULL)
	{
		*root = new_node;
		return ;
	}
	current = *root;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
}

int	main(void)
{
	t_stack_node	*root;
	t_stack_node	*current;

	root = NULL;

	insert_stack(&root, 5);
	insert_stack(&root, -2);
	insert_stack(&root, 6);

	current = root;
	while (current != NULL)
	{
		if (current->content != NULL)
			printf("%d\n", *(current->content));
		else
			printf("Content is NULL \n");
		current = current->next;
	}

	return (0);
}