#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

typedef struct instruct_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int num_line);
} instruct_t;

void push(stack_t **stack, unsigned int num_line);
void pall(stack_t **stack);
void pint(stack_t **stack, unsigned int num_line);
void pop(stack_t **stack, unsigned int num_line);
void swap(stack_t **stack, unsigned int num_line);
void add(stack_t **stack, unsigned int num_line);
void nop(stack_t **stack);
int is_integer(const char *str);
void free_stack(stack_t *stack);

#endif
