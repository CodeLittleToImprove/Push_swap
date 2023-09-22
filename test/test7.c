# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <ctype.h>
# include <string.h>
# include <limits.h>

typedef struct s_stack
{
	int							*content;
	struct s_stack				*next;
}	t_stack;

typedef struct s_stack_data_set
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_stack_data_set;

t_stack_data_set	*init_stacks_struct(void)
{
	t_stack_data_set	*set;

	set = malloc(sizeof(t_stack_data_set));
	if (!set)
		return (NULL);
	set->stack_a = NULL;
	set->stack_b = NULL;
	return (set);
}

void	insert_stack(t_stack **root, int value)
{
	t_stack	*new_node;
	t_stack	*current;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
	{
		perror("Error allocating memory for new node");
		exit(1);
	}
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
	if (current == NULL)
	{
		perror("Error: Attempted to insert into an empty stack");
		exit(1);
	}
	printf("Traversing the list:\n");
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new_node;
}

t_stack	*create_list(char **input_array)
{
	size_t			index;
	t_stack			*stack_a;

	stack_a = NULL;

	index = 0;

	while (input_array[index])
	{

		insert_stack(&stack_a, atoi(input_array[index]));
		if (!stack_a)
			return (NULL);

		index++;

	}
	return (stack_a);
}

t_stack	*init_stack_a(char *argv[])
{
	t_stack		*stack_a;
	char		**input_array;


	input_array = argv;

	stack_a = create_list(input_array);

	return (stack_a);
}

void	push(t_stack **dest, t_stack **src)
{
	t_stack *node_to_push;

	if (*src == NULL)
		return;
	node_to_push = *src;
	*src = (*src)->next;
	if (*dest == NULL) {
		*dest = node_to_push;
		node_to_push->next = NULL;
	} else
	{
		node_to_push->next = *dest;
		*dest = node_to_push;
	}
	// maybe need to add check if there is a next element otherwise set next to Null?
}
void	pa(t_stack **a, t_stack**b)
{
	push(a, b);
}

void	pb(t_stack**b, t_stack **a)
{
	push(b, a);
}
void	print_stack(t_stack *stack)
{
	t_stack		*current;
	size_t		index;

	current = stack;
	index = 0;

	if (current == NULL)
		printf("current is null\n");

	while (current != NULL)
	{
		printf("Element[%zu] is %d\n", index, *current->content);
		current = current->next;
		index++;
	}

}

int	main(void)
{
	t_stack_data_set	*set;
	char *argv[] = {"5", "3", "1" ,'\0'};
	char *argv2[] = {"9",'\0'};
		set = init_stacks_struct();
		if (!set)
			return (1);

		set->stack_a = init_stack_a(argv);
		print_stack(set->stack_a);
		printf("finished printing stack a\n");
		set->stack_b = init_stack_a(argv2);
		print_stack(set->stack_b);
		printf("finished printing stack b\n");
		pb(&set->stack_b, &set->stack_a);
		print_stack(set->stack_a);
		printf("finished printing stack a\n");
		print_stack(set->stack_b);
		printf("finished printing stack b\n");

	free(set);
	return (0);
}
