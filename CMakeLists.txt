cmake_minimum_required(VERSION 3.25)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

# Add the library file
add_library(libft STATIC IMPORTED
        test/test8.c)
set_target_properties(libft PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libft/libft.a)

add_executable(push_swap
        push_swap.h
        input_validation.c
        main.c
        error_handler.c
        stack_init.c
        test_utils.c
        utils.c
        linked_list_utils.c
        push_command.c
        swap_command.c
        rotate_command.c)

# Link the executable with the libft library
target_link_libraries(push_swap libft)

