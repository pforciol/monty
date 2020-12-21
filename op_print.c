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

void _pchar(stack_t **stack, unsigned int line_nb)
{
	if (!*stack || !stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_nb);
		META.error = 1;
	}
	else if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_nb);
		META.error = 1;
	}
	else
	{
		printf("%c\n", (*stack)->n);
	}
}

void _pstr(stack_t **stack, unsigned int line_nb)
{
	stack_t *cur = *stack;

	if (!*stack || !stack)
	{
		fprintf(stderr, "L%d: can't pstr, stack empty\n", line_nb);
		META.error = 1;
	}
	else
	{
		while (cur)
		{
			if ((cur->n <= 0 || cur->n > 127))
				break;
			printf("%c", cur->n);
			cur = cur->next;
		}
		printf("\n");
	}
}
