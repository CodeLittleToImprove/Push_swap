#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"


typedef struct s_stack
{
    int							*content;
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
    if(current == NULL)
        write(STDERR_FILENO, "error", 6);
    while (current->next != NULL)
        current = current->next;
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

t_stack	*create_list(char **input_array, int argc)
{
    size_t			index;
    t_stack			*stack_a;

    index = 1;

    while (index < argc)
    {
        insert_stack(&stack_a, atoi(input_array[index]));
        index++;
    }

    return (stack_a);
}

t_stack	*init_stack_a(char *argv[], int argc)
{
    t_stack		*stack_a;
    char		**input_array;

    input_array = argv + 1;

    stack_a = create_list(input_array, argc);
    return (stack_a);
}


int	main(int argc, char *argv[])
{
    t_stack_data *set;
    set = init_stacks_struct();
    if (!set)
        return (1);
    set->stack_a = init_stack_a(argv, argc);
}