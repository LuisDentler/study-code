/*
 * File: main.c
 * Description:
 * Demonstrates command-line argument handling using
 * array indexing and pointer dereferencing.
 */

#include <stdio.h>
#include <string.h>

/**
 * @brief Print command-line arguments using array indexing
 *
 * Iterates over all command-line arguments (except program name)
 * using the [] operator and prints index, address, content and length.
 *
 * @param[in] argc Number of command-line arguments
 * @param[in] argv Argument vector
 */
static void print_arguments_with_indexing(int argc, char **argv)
{
    int index = 0;

    for (index = 1; index < argc; index++)
    {
        printf("Index   : %d\n", index);
        printf("Address : %p\n", (void *)&argv[index]);
        printf("Content : %s\n", argv[index]);
        printf("Length  : %zu\n\n", strlen(argv[index]));
    }
}

/**
 * @brief Print command-line arguments using pointer dereferencing
 *
 * Iterates over all command-line arguments (except program name)
 * using pointer arithmetic and dereferencing.
 *
 * @param[in] argc Number of command-line arguments
 * @param[in] argv Argument vector
 */
static void print_arguments_with_pointers(int argc, char **argv)
{
    char **p_argument = NULL;
    int index = 1;

    p_argument = argv + 1;

    while (p_argument < (argv + argc))
    {
        printf("Index   : %d\n", index);
        printf("Address : %p\n", (void *)p_argument);
        printf("Content : %s\n", *p_argument);
        printf("Length  : %zu\n\n", strlen(*p_argument));

        p_argument++;
        index++;
    }
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Error: Please provide at least one argument.\n");
        return 1;
    }

    printf("=== Array Indexing Variant ===\n\n");
    print_arguments_with_indexing(argc, argv);

    printf("=== Pointer Dereferencing Variant ===\n\n");
    print_arguments_with_pointers(argc, argv);

    return 0;
}