/* opcode_functions.c */
#include "monty.h"

void free_stack(stack_t *stack) {
    stack_t *current = stack;
    while (current != NULL        stack_t *temp = current;
        current = current->next;
        free(temp);
    }
}

void push(stack_t **stack, unsigned int line_number) {
    int value;
    char *arg = strtok(NULL, " \t\n");

    if (arg == NULL || !is_integer(arg)) {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = atoi(arg);
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;
    if (*stack != NULL) {
        (*stack)->prev = new_node;
    }
    *stack = new_node;
}

void pall(stack_t **stack, unsigned int line_number) {
    stack_t *current = *stack;

    while (current != NULL) {
        printf("%d\n", current->n);
        current = current->next;
    }
}

void pint(stack_t **stack, unsigned int line_number) {
    if (*stack == NULL) {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}

void pop(stack_t **stack, unsigned int line_number) {
    if (*stack == NULL) {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *temp = *stack;
    *stack = (*stack)->next;
    if (*stack != NULL) {
        (*stack)->prev = NULL;
    }
    free(temp);
}

void swap(stack_t **stack, unsigned int line_number) {
    if (*stack == NULL || (*stack)->next == NULL) {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *first = *stack;
    stack_t *second = first->next;

    first->next = second->next;
    if (second->next != NULL) {
        second->next->prev = first;
    }
    second->prev = NULL;
    second->next = first;
    first->prev = second;
    *stack = second;
}

void add(stack_t **stack, unsigned int line_number) {
    if (*stack == NULL || (*stack)->next == NULL) {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    int result = (*stack)->n + (*stack)->next->n;
    pop(stack, line_number);
    (*stack)->n = result;
}

void nop(stack_t **stack, unsigned int line_number) {
    /* This function does nothing */
}

int is_integer(const char *str) {
    if (str == NULL || *str == '\0') {        return 0;
    }
    if (*str == '-' || *str == '+') {
        str++;
    }
    while (*st        if (*str < '0' || *str > '9') {
            return 0;
        }
        str++;
    }
    return 1;
}
