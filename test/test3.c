#include <stdio.h>
#include <stdlib.h>
# include <stdbool.h>
#include <string.h>

int    ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t    index;

	index = 0;
	if (n == 0)
	{
		return (0);
	}
	while (index < n && (*s1 || *s2))
	{
		if (*s1 != *s2)
			return ((unsigned char )*s1 - (unsigned char )*s2);
		index++;
		s1++;
		s2++;
	}
	return (0);
}

bool    is_not_a_duplicate(char *argv[], int size)
{
	size_t    outer_index;
	size_t    inner_index;

	outer_index = 1;
	while (outer_index < size -1)
	{
		inner_index = outer_index + 1;
		while (inner_index <= size)
		{
			// maybe add check which string is longer and then use that string for strncmp
			if (ft_strncmp(argv[outer_index], argv[inner_index],
						   strlen(argv[outer_index])) == 0)
				return (false);
			inner_index++;
		}
		outer_index++;
	}

	return (true);
}

int main(int argc, char *argv[])
{
	// If no command-line arguments are provided

	argv = NULL;
	if (argc == 1) {
		char *manualArgs[] = {
				"program_name", // Set the program name as the first argument
				"1",
				"2",
				"12"
		};

		// Set the argv array manually
		argv = manualArgs;
	}
	int size = 3;

	if(is_not_a_duplicate(argv, size))
	{
		printf("True");
	}
	else
	{
		printf("False");
	}
	return (0);
}