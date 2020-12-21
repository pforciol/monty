#include "monty.h"

void _add(stack_t **stack, unsigned int line_nb)
{
	if (!*stack || !stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_nb);
		META.error = 1;
	}
	else
	{
		_math(stack, '+');
	}
}

void _sub(stack_t **stack, unsigned int line_nb)
{
	if (!*stack || !stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_nb);
		META.error = 1;
	}
	else
	{
		_math(stack, '-');
	}
}

void _div(stack_t **stack, unsigned int line_nb)
{
	if (!*stack || !stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_nb);
		META.error = 1;
	}
	else
	{
		_math(stack, '/');
		if (META.error == 1)
			fprintf(stderr, "L%d: division by zero\n", line_nb);
	}
}

void _mul(stack_t **stack, unsigned int line_nb)
{
	if (!*stack || !stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_nb);
		META.error = 1;
	}
	else
	{
		_math(stack, '*');
	}
}

void _mod(stack_t **stack, unsigned int line_nb)
{
	if (!*stack || !stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_nb);
		META.error = 1;
	}
	else
	{
		_math(stack, '%');
		if (META.error == 1)
			fprintf(stderr, "L%d: division by zero\n", line_nb);
	}
}
