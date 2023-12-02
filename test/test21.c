#include <stdio.h>
# include <stdbool.h>

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
	{
		printf("first if \n");
		return (false);
	}

	if ((*str_nbr == '+' || *str_nbr == '-')
		&& !is_valid_digit(str_nbr[1]))
	{
		printf("second if \n");
		return (false);
	}

	while (*++str_nbr)
	{
		if (!is_valid_start_character(*str_nbr))
		{
			printf("third if \n");
			return (false);
		}

	}
	return (true);
}

int main() {
	char input1[] = "a";
	char input2[] = "-12 4";
	char input3[] = "++789";
	char input4[] = "+789abc123";

	if (is_valid_number(input1))
		printf("%s is a valid number.\n", input1);
	else
		printf("%s is not a valid number.\n", input1);

	if (is_valid_number(input2))
		printf("%s is a valid number.\n", input2);
	else
		printf("%s is not a valid number.\n", input2);

	if (is_valid_number(input3))
		printf("%s is a valid number.\n", input3);
	else
		printf("%s is not a valid number.\n", input3);

	if (is_valid_number(input4))
		printf("%s is a valid number.\n", input4);
	else
		printf("%s is not a valid number.\n", input4);

	return 0;
}
