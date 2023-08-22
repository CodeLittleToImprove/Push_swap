#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	// If no command-line arguments are provided
	printf("%d\n", argc);
	argv = NULL;
//	if (argc == 1) {
//		char *manualArgs[] = {
//				"program_name", // Set the program name as the first argument
//				"1",
//				"2",
//				"12"
//		};
//
//		// Set the argv array manually
//		argv = manualArgs;
//
//		// Now you can work with the modified argv array
//		for (int i = 0; i <= 3; i++) {
//			printf("Modified argv[%d]: %s\n", i, argv[i]);
//		}
//	} else {
//		// Work with the original argv array
//		for (int i = 0; i <= 3; i++) {
//			printf("Original argv[%d]: %s\n", i, argv[i]);
//		}
//	}

	return (0);
}