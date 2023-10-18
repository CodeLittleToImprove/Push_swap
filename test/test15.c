# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <ctype.h>
# include <string.h>
# include <limits.h>

typedef struct s_stack
{
	int							content;
	struct s_stack				*next;
	int 						index;
//	struct s_stack			*prev;
}	t_stack;

typedef struct s_stack_data_set
{
	t_stack    *stack_a;
	t_stack    *stack_b;
}    t_stack_data_set;

t_stack_data_set    *init_stacks_struct(void)
{
	t_stack_data_set    *set;

	set = malloc(sizeof(t_stack_data_set));
	if (!set)
		return (NULL);
	set->stack_a = NULL;
	set->stack_b = NULL;
	return (set);
}
// maybe don't malloc content change to be a normal int
void	insert_stack(t_stack **root, int value)
{
	t_stack	*current;
	t_stack	*new_node;

	current = NULL;
	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
	{
		exit(1);
	}
	new_node->content = value;
	new_node->index = -1;
	new_node->next = NULL;
	if (*root == NULL)
		*root = new_node;
	else
	{
		current = *root;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}

t_stack    *create_list(char **input_array)
{
	size_t            index;
	t_stack            *stack_a;

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

t_stack    *init_stack_a(char *argv[])
{
	t_stack        *stack_a;
	char        **input_array;


	input_array = argv;

	stack_a = create_list(input_array);

	return (stack_a);
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
		printf("Element[%zu] is %d\n", index, current->content);
		current = current->next;
		index++;
	}
}

int	is_max(t_stack **stack_a)
{
	t_stack		*root;
	int			max;

	root = *stack_a;
	max = 0;
	max = root->content;
	while (root->next)
	{
		root = root->next;
		if (root->content > max)
			max = root->content;
	}
	return (max);
}
void	sort3(t_stack **stack_a, int stack_len)
{
	int max;
	if (stack_len != 3)
		return;
	max = is_max(&*stack_a);
	if (max == (*stack_a)->content)
	{
		printf("run ra \n");
		ra(&*stack_a);
	}

	if (max == (*stack_a)->next->content)
	{
		printf("run rra \n");
		rra(&*stack_a);
	}
	if ((*stack_a)->content > (*stack_a)->next->content)
	{
		printf("run sa \n");
		sa(&*stack_a);
	}
}

void sort_check(t_stack **stack_a, t_stack **stack_b)
{
		printf("sort3 start\n");
		sort3(stack_a);
		printf("sort3 successful\n");

}
int    main(void)
{
	t_stack_data_set    *set;
	bool				sorted;
	char *argv[] = {"5", "2", "3", '\0'};

	set = init_stacks_struct();
	if (!set)
		return (1);
	set->stack_a = init_stack_a(argv);
	print_stack(set->stack_a);
	printf("finished print stack_a\n");
	sort_check(&set->stack_a, &set->stack_b);
	printf("after_sort3\n");
	print_stack(set->stack_a);


	return (0);
}



