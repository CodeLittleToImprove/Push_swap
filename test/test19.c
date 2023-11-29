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
	int							index;
}	t_stack;

typedef struct s_stack_data_set
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_stack_data_set;

static int	count_words(const char *str, char c)
{
	int i;
	int trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char		**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	if (!s || !(split = malloc((count_words(s, c) + 1) * sizeof(char *))))
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

void	process_arguments(int argc, char *argv[], size_t *size, char ***input)
{
	if (argc <= 1)
	{
		*size = 0;
		*input = NULL;
		exit(0);
	}
	if (argc == 2)
		*input = ft_split(argv[1], ' ');
	else
		*input = argv + 1;
	*size = argc - 1;
}

bool	is_valid_start_character(char c)
{
	return (c == '+' || c == '-' || (c >= '0' && c <= '9'));
}

bool	is_valid_digit(char c)
{
	return (c >= '0' && c <= '9');
}

bool	is_valid_number(char *str_nbr)
{
	if (!is_valid_start_character(*str_nbr))
		return (false);
	if ((*str_nbr == '+' || *str_nbr == '-') && !is_valid_digit(str_nbr[1]))
		return (false);
	while (*++str_nbr)
	{
		if (!is_valid_digit(*str_nbr))
			return (false);
	}
	return (true);
}

bool	is_valid_int_range(char *str_nbr)
{
	if (atoll(str_nbr) > INT_MAX || atoll(str_nbr) < INT_MIN)
		return (false);

	return(true);
}

bool	is_array_not_a_duplicate(char **input, size_t size)
{
	size_t	outer_index;
	size_t	inner_index;
	size_t	max_int_len;

	outer_index = 0;
	max_int_len = 20;
	while (outer_index < size -1)
	{
		inner_index = outer_index + 1;
		while (inner_index < size)
		{
			if (strncmp(input[outer_index], input[inner_index],
						max_int_len) == 0)
			{
				printf("is a duplicate\n");
				return (false);
			}
			inner_index++;
		}
		outer_index++;
	}
	printf("is not a duplicate\n");
	return (true);
}

bool	is_valid_input(char **input, size_t size)
{
	size_t	index;

	index = 0;

	if (is_array_not_a_duplicate(input, size))
	{
		while (input[index] != NULL)
		{
//			printf("entry checked %s\n", input[index]);
			if (!is_valid_number(input[index]) || !is_valid_int_string(input[index]))
			{
				return (false);
			}

			index++;
		}
//		printf("input valid\n");
		return (true);
	}
	else
	{
//		printf("input invalid\n");
		return (false);
	}
}

int	main(int argc, char *argv[])
{
	t_stack_data_set	*set;
	size_t				size;
	char				**input;

	process_arguments(argc, argv, &size, &input);
	if (is_valid_input(input, size) == true)
	{
		printf("valid input\n");
	}
	else
	{
		printf("in else\n");
		return (write(STDERR_FILENO, "Error\n", 6), -1);
	}

}
