#include "monty.h"

#define MAX_LENGTH_LINE 1024

int main(int argc, char *argv[])
{
    FILE *file;
    char lines[MAX_LENGTH_LINE];
    stack_t *stack = NULL;
    unsigned int num_line = 0;
    char *opcode;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(lines, sizeof(lines), file) != NULL)
    {
        num_line++;
        opcode = strtok(lines, " \t\n");

        if (opcode == NULL || opcode[0] == '#')
        {
            continue;
        }

        if (strcmp(opcode, "push") == 0)
        {
            push(&stack, num_line);
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall(&stack);
        }
        else if (strcmp(opcode, "pint") == 0)
        {
            pint(&stack, num_line);
        }
        else if (strcmp(opcode, "pop") == 0)
        {
            pop(&stack, num_line);
        }
        else if (strcmp(opcode, "swap") == 0)
        {
            swap(&stack, num_line);
        }
        else if (strcmp(opcode, "add") == 0)
        {
            add(&stack, num_line);
        }
        else if (strcmp(opcode, "nop") == 0)
        {
            nop(&stack);
        }
        else
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", num_line, opcode);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
    free_stack(stack);
    return 0;
}