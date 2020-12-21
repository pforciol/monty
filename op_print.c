#include "monty.h"

void _pint(stack_t **stack, unsigned int line_nb)
{
	if (!*stack || !stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_nb);
		META.error = 1;
	}
	else
	{
		printf("%d\n", (*stack)->n);
	}
}

void _pall(stack_t **stack, unsigned int line_nb)
{
    stack_t *cur = *stack;
	(void)line_nb;

    while (cur)
    {
        printf("%d\n", cur->n);
        cur = cur->next;
    }
}

void _nop(stack_t **stack, unsigned int line_nb)
{
	(void)stack;
	(void)line_nb;
}

