#include "monty.h"

void _pall(stack_t **stack, unsigned int line_nb)
{
    (void)line_nb;

    while (*stack)
    {
        printf("%d\n", (*stack)->n);
        *stack = (*stack)->next;
    }

	META.error = 0;
}
