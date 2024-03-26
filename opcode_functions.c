#include "monty.h"

void free_stack(stack_t *stack)
{
    stack_t *current = stack;
    while (current != NULL)
    {
        stack_t *temp = current;
        current = current->next;
        free(temp);
    }
}

void push(stack_t **stack, unsigned int num_line)
{
    char *arg;
    int value;
    stack_t *new_node;

    arg = strtok(NULL, " \t\n");
    if (arg == NULL || !is_integer(arg))
    {
        fprintf(stderr, "L%u: usage: push integer\n", num_line);
        exit(EXIT_FAILURE);
    }

    value = atoi(arg);
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
    {
        (*stack)->prev = new_node;
    }

    *stack = new_node;
}

void pall(stack_t **stack)
{
    stack_t *current;

    current = *stack;
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

void pint(stack_t **stack, unsigned int num_line)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", num_line);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}

void pop(stack_t **stack, unsigned int num_line)
{
    stack_t *temp;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", num_line);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = (*stack)->next;
    if (*stack != NULL)
    {
        (*stack)->prev = NULL;
    }
    free(temp);
}

void swap(stack_t **stack, unsigned int num_line)
{
    stack_t *first, *second;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", num_line);
        exit(EXIT_FAILURE);
    }

    first = *stack;
    second = first->next;

    first->next = second->next;
    if (second->next != NULL)
    {
        second->next->prev = first;
    }
    second->prev = NULL;
    second->next = first;
    first->prev = second;
    *stack = second;
}

void add(stack_t **stack, unsigned int num_line)
{
    int result;
    /*stack_t *temp;*/

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", num_line);
        exit(EXIT_FAILURE);
    }

    result = (*stack)->n + (*stack)->next->n;
    pop(stack, num_line);
    (*stack)->n = result;
}

void nop(stack_t **stack)
{
    /* This function does nothing*/
    (void)stack;
}

int is_integer(const char *str)
{
    if (str == NULL || *str == '\0')
    {
        return 0;
    }
    if (*str == '-' || *str == '+')
    {
        str++;
    }
    while (*str != '\0')
    {
        if (*str < '0' || *str > '9')
        {
            return 0;
        }
        str++;
    }
    return 1;
}
