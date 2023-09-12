#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>  // For isdigit() function
#include <string.h> // For strlen() function

bool is_valid_input(const char *input) {
	int length = strlen(input);
	int i = 0;

	// Check for quotes at the beginning and end
	if (length < 2 || input[0] != '"' || input[length - 1] != '"') {
		return false;
	}

	// Skip the opening quote
	i++;

	while (i < length - 1) {
		if (input[i] == ' ' && input[i - 1] == ' ') {
			// Disallow consecutive spaces
			return false;
		} else if (!isdigit(input[i]) && !(input[i] == '-' && (i == 1 || input[i - 1] == ' '))) {
			// Check if the character is a digit or a minus sign for negative numbers
			return false;
		}
		i++;
	}

	return true;
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Usage: %s <input>\n", argv[0]);
		return 1;
	}

	if (is_valid_input(argv[1])) {
		printf("Input is valid.\n");
	} else {
		printf("Error: Invalid input format.\n");
		return 2; // Return an error code
	}

	// Your push_swap logic here...

	return 0;
}
