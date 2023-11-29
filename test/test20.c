#include <stdio.h>
#include <stdbool.h>
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

bool    is_array_not_a_duplicate(char **input, size_t size)
{
	size_t    outer_index;
	size_t    inner_index;
	size_t    max_int_len;

	outer_index = 0;
	max_int_len = 20;
	while (outer_index < size -1)
	{
		inner_index = outer_index + 1;
		while (inner_index < size)
		{
			if (ft_strncmp(input[outer_index], input[inner_index],
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

int main() {
	// Example usage with a one-dimensional array
	char *oneDimArray[] = {"1", "2", "3", "1"};
	size_t sizeOneDim = sizeof(oneDimArray) / sizeof(oneDimArray[0]);

	if (is_array_not_a_duplicate(oneDimArray, sizeOneDim)) {
		printf("No duplicates in one-dimensional array.\n");
	} else {
		printf("Duplicates found in one-dimensional array.\n");
	}

	// Example usage with a two-dimensional array
	char *twoDimArray[][2] = {{"1", "1"}, {"2", "2"}, {"3", "3"}, {"1", "1"}};
	size_t sizeTwoDim = sizeof(twoDimArray) / sizeof(twoDimArray[0]);

	if (is_array_not_a_duplicate(twoDimArray, sizeTwoDim)) {
		printf("No duplicates in two-dimensional array.\n");
	} else {
		printf("Duplicates found in two-dimensional array.\n");
	}

	return 0;
}