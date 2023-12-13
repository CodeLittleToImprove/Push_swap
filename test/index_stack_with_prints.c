t_stack	*get_next_min_node(t_stack *stack)
{
	t_stack		*root;
	t_stack		*min;
	bool		has_min;
	int index = 0;
//	int num1;
//	int num2;

	root = stack;
	min = NULL;
	has_min = false;
	if (root)
	{
		while (root)
		{
//			num1 = root->content;
//			num2 = min->content;
//			printf("check num1: %d < num2: %d\n", num1, num2);
			printf("root content before if: %d \n", root->content);
			printf("root index before if: %d \n", root->index);
			if(min != NULL)
				printf("min content before if: %d \n", min->content);
			if ((root->index == -1) && ((!has_min)
					|| (root->content < min->content)))
			{
				index++;
				printf("index= %d\n", index);
				min = root;
				printf("min content in if: %d \n", min->content);
				has_min = true;
			}
			printf("in else case\n");
			root = root->next;
		}
	}
	if (min != NULL)
		printf("min content which get returned : %d \n", min->content);
	return (min);
}

void	index_stack(t_stack **stack)
{
	int			index;
	t_stack		*root;

	index = 0;
	root = get_next_min_node(*stack);
	printf("outside while\n");
//	printf("root content before while: %d \n", root->content);
//	printf("root index before while: %d \n", root->index);
	while (root)
	{
//		printf("index %d\n", index);
		root->index = ++index;
//		printf("root index after index++: %d \n", root->index);
		root = get_next_min_node(*stack);
		if(root != NULL)
			printf("root content after while: %d \n", root->content);
//		printf("root index after while: %d \n", root->index);
	}
}
