/*
 * File: section1_file_io.c
 * Description: Demonstrates basic file input and output functions in C
 */

#include <stdio.h>
#include <stdlib.h>

#define INPUT_FILE_NAME  "example_input.txt"
#define OUTPUT_FILE_NAME "example_output.txt"
#define LINE_BUFFER_SIZE 100

int main(void)
{
    FILE *p_input_file = NULL;
    FILE *p_output_file = NULL;

    char line_buffer[LINE_BUFFER_SIZE] = {0};
    char single_char = '\0';
    int scanned_value = 0;

    /* Open output file */
    p_output_file = fopen(OUTPUT_FILE_NAME, "w");
    if (p_output_file == NULL)
    {
        printf("Error: Could not open output file.\n");
        return 1;
    }

    /* Writing using fputc */
    fputc('A', p_output_file);
    fputc('\n', p_output_file);

    /* Writing using fputs */
    fputs("This is a test line.\n", p_output_file);

    /* Writing using fprintf */
    fprintf(p_output_file, "Formatted number: %d\n", 42);

    fclose(p_output_file);

    /* Open input file */
    p_input_file = fopen(INPUT_FILE_NAME, "r");
    if (p_input_file == NULL)
    {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    /* Reading using fgetc */
    single_char = (char)fgetc(p_input_file);
    printf("First character (fgetc): %c\n", single_char);

    /* Reset file position */
    rewind(p_input_file);

    /* Reading using fgets */
    if (fgets(line_buffer, LINE_BUFFER_SIZE, p_input_file) != NULL)
    {
        printf("First line (fgets): %s", line_buffer);
    }

    /* Reset file position */
    rewind(p_input_file);

    /* Reading using fscanf */
    if (fscanf(p_input_file, "%d", &scanned_value) == 1)
    {
        printf("Scanned integer (fscanf): %d\n", scanned_value);
    }

    fclose(p_input_file);

    return 0;
}