cmake_minimum_required(VERSION 3.25)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

# Add the libft library
add_library(libft STATIC IMPORTED)
set_target_properties(libft PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/libft/libft.a)

# Add the ft_printf library
add_library(ft_printf STATIC IMPORTED)
set_target_properties(ft_printf PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/ft_printf/libftprintf.a)

add_executable(push_swap
        push_swap.h
        input_validation.c
        main.c
        array_cleanup.c
        stack_init.c
        test_utils.c
        utils.c
        linked_list_utils.c
        push_command.c
        swap_command.c
        rotate_command.c
        reverse_rotate_command.c
        sort_utils.c
        radix_sort.c
        sort_up_to_five.c)

# Link the executable with the libft and ft_printf libraries
target_link_libraries(push_swap PRIVATE libft ft_printf)
