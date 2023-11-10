#include <stdio.h>
#include <stdlib.h>
// shorten for pythontutor not exact enough
typedef struct s_stack {
	int content;
	struct s_stack *next;
	int index;
} t_stack;

t_stack *create_stack_array(int content_values[], int index_values[], int num_elements) {
	t_stack *stack_array = (t_stack *)malloc(num_elements * sizeof(t_stack));
	for (int i = 0; i < num_elements; i++) {
		stack_array[i].content = content_values[i];
		stack_array[i].index = index_values[i];
		stack_array[i].next = (i < num_elements - 1) ? &stack_array[i + 1] : NULL;
	}
	return stack_array;
}
void    push(t_stack **dest, t_stack **src)
{
	t_stack *node_to_push;
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
void    pa(t_stack **a, t_stack **b)
{
	push(a, b);
}
void    pb(t_stack **b, t_stack **a)
{
	push(b, a);
}
void    rotate(t_stack **stack_x)
{
	t_stack    *first_element;
	t_stack    *second_element;
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
void    ra(t_stack **stack_a)
{
	rotate(stack_a);
}
int                    get_max_bits(t_stack **stack)
{
	t_stack    *current = *stack;
	int        max = current->index;
	int        max_bits= 0;
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

void    radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int    stack_len = 6;
	int    max_bits = get_max_bits(stack_a);
	int    outer_index  = 0;
	int    inner_index;
	while (outer_index < max_bits)
	{
		inner_index = 0;
		while(inner_index++ <= stack_len)
		{
			if (((*stack_a)->index >> outer_index) & 1)
				ra(&*stack_a);
			else
			{
				pb(&*stack_b, &*stack_a);
			}
			while (*stack_b != NULL)
				pa(&*stack_a, &*stack_b);
		}
		outer_index++;
	}
}
int main() {
	int content_values[] = {5, 4, 1,3, 2, 9};
	int index_values[] = {5, 4, 1, 3, 2, 6};
	int num_elements = sizeof(content_values) / sizeof(content_values[0]);
	t_stack *stack_a = create_stack_array(content_values, index_values, num_elements);
	t_stack *stack_b = NULL;
	radix_sort(&stack_a, &stack_b);
	free(stack_a );

	return 0;
}