# include <stdlib.h>
# include <string.h>
typedef struct s_stack
{
	int                         content;
	struct s_stack              *next;
	int                         index;
}    t_stack;
typedef struct s_stack_data_set
{
	t_stack    *stack_a;
	t_stack    *stack_b;
}    t_stack_data_set;
t_stack *create_list(char **input_array)
{
	t_stack *stack_a = NULL;
	for (size_t index = 0; input_array[index]; index++)
	{
		t_stack *new_node = malloc(sizeof(t_stack));
		new_node->content = atoi(input_array[index]);
		new_node->index = -1;
		new_node->next = NULL;
		if (!stack_a)
		{
			stack_a = new_node;
		}
		else
		{
			t_stack *current = stack_a;
			while (current->next)
			{
				current = current->next;
			}
			current->next = new_node;
		}
	}
	return stack_a;
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
}
void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
}
void	pb(t_stack **b, t_stack **a)
{
	push(b, a);
}
void	rotate(t_stack **stack_x)
{
	t_stack	*first_element;
	t_stack	*second_element;
	t_stack *new_first_element;
	if (*stack_x == NULL || (*stack_x)->next == NULL)
		return;
	first_element = *stack_x;
	second_element = first_element->next;
	new_first_element = second_element;
	first_element->next = NULL;
	while (second_element->next != NULL)
		second_element = second_element->next;
	second_element->next = first_element;
	*stack_x = new_first_element;
}
void	ra(t_stack **stack_a)
{
	rotate(stack_a);
}
int                    get_max_bits(t_stack **stack)
{
	t_stack    *current = *stack;
	int        max = current->index;
	int        max_bits = 0;
	while(current)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
	while ((max >> max_bits) != 0)
		++max_bits;
	return (max_bits);
}
void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_len = 6;
	int	max_bits = get_max_bits(stack_a);
	int	outer_index = 0;
	int	inner_index;
//	while (outer_index < max_bits)
//	{
//		inner_index = 0;
//		while(inner_index++ <= stack_len)
//		{
//			if (((*stack_a)->index >> outer_index) & 1)
//				ra(&*stack_a);
//			else
//			{
//				pb(&*stack_b, &*stack_a);
//			}
//			while (*stack_b != NULL)
//				pa(&*stack_a, &*stack_b);
//		}
//		outer_index++;
//	}
}
// what is this why does it crash when I just call radix sort
int    main(void)
{
	t_stack_data_set    *set;
	char *argv[] = {"5", "4", "1", "3", "2" ,"9",'\0'};
	set->stack_a = init_stack_a(argv); // this leads to an error in pythontutor
	set->stack_a = NULL;
//	radix_sort(&set->stack_a, &set->stack_b);
	return (0);
}