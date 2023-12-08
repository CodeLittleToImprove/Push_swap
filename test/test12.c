# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <ctype.h>
# include <string.h>
# include <limits.h>

// no prints example of push
typedef struct s_stack
{
	int                            *content;
	struct s_stack                *next;
}    t_stack;

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
void    insert_stack(t_stack **root, int value)
{
	t_stack    *new_node;
	t_stack    *current;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
	{
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
		*root = new_node;
	else
	{
		current = *root;
		while (current->next != NULL)
		{
			current = current->next;
		}
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

void	reverse_rotate(t_stack **stack_x)
{
	t_stack	*first_element;
	t_stack *second_last_element;
	t_stack *current_element;

	if (*stack_x == NULL || (*stack_x)->next == NULL)
		return;
	first_element = *stack_x;
	current_element = first_element;
	while (current_element->next != NULL)
	{
		second_last_element = current_element;
		current_element = current_element->next;
	}
	second_last_element->next = NULL;
	current_element->next = first_element;
	*stack_x = current_element;
}

void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
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

int    main(void)
{
	t_stack_data_set    *set;
	char *argv[] = {"1", "2", "3", "4", "5", '\0'};
	char *argv2[] = {"5", "4", "3", "2", "1", '\0'};
	set = init_stacks_struct();
	if (!set)
		return (1);
	set->stack_a = init_stack_a(argv);
	set->stack_b = init_stack_a(argv2);
	print_stack(set->stack_a);
	printf("StackA printed \n");
	print_stack(set->stack_b);
	printf("Stacks printed pre reverserotate\n");
	rrr(&set->stack_a, &set->stack_b);
	print_stack(set->stack_a);
	printf("StackA printed \n");
	print_stack(set->stack_b);

//	print_stack(set->stack_a);
//	ft_printf("StackA printed \n");
//	print_stack(set->stack_b);
//	ft_printf("StackB printed \n");
//	ss(&set->stack_a, &set->stack_b);
//	print_stack(set->stack_a);
//	ft_printf("StackA printed \n");
//	print_stack(set->stack_b);
//	ft_printf("StackB printed \n");
	free(set);
	return (0);
}