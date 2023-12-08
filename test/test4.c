#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"


typedef struct s_stack
{
	int						*content;
	struct s_stack			*next;
}	t_stack;

typedef struct s_stack_data_set
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_stack_data;

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
//	ft_printf("Allocated memory for new node at address: %p\n", (void *)new_node);
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
//		ft_printf("Should happen only once \n");
		*root = new_node;
		return ;
	}
	printf("current pointer value before setting root: %p\n", (void *)current);
	current = *root;
	printf("current pointer value after setting root: %p\n", (void *)current);
	if (current == NULL)
	{
//		ft_printf("I am hopefully not here");
		perror("Error: Attempted to insert into an empty stack");
		exit(1);
	}
//	if (current->next == NULL)
//		ft_printf("something went wrong \n");
	while (current->next != NULL)
	{
		printf("current pointer value before setting next: %p\n", (void *)current);
		current = current->next;
		printf("current pointer value after setting next: %p\n", (void *)current);
	}
	current->next = new_node;
}

t_stack_data	*init_stacks_struct(void)
{
	t_stack_data	*set;

	set = malloc(sizeof(t_stack_data));
	if (!set)
		return (NULL);
	set->stack_a = NULL;
	set->stack_b = NULL;
	return (set);
}

t_stack	*create_list(char **input_array)
{
	size_t			index;
	t_stack			*stack_a;

	stack_a = NULL;

	index = 0;

	while (input_array[index])
	{
		printf("Inserting element %zu\n", atoi(input_array[index]));
		insert_stack(&stack_a, atoi(input_array[index]));

		index++;

	}
	return (stack_a);
}
t_stack	*init_stack_a(char *argv[])
{
	t_stack		*stack_a;
	char		**input_array;

//	input_array = argv + 1;
	input_array = argv;

	stack_a = create_list(input_array);

	return (stack_a);
}

int	main(int argc, char *argv[])
{
    t_stack_data *set;
    set = init_stacks_struct();
    if (!set)
        return (1);
    set->stack_a = init_stack_a(argv);
}