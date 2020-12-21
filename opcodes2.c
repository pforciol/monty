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

