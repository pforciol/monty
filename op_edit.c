#include "monty.h"

void _pop(stack_t **stack, unsigned int line_nb)
{
	stack_t *tmp;

	if (!*stack || !stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_nb);
		META.error = 1;
	}
	else if ((*stack)->next)
	{
		tmp = (*stack)->next;
		tmp->prev = NULL;
		free(*stack);
		*stack = tmp;
	}
}

void _swap(stack_t **stack, unsigned int line_nb)
{
	 int tmp = 0;

	if (!*stack || !stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_nb);
		META.error = 1;
	}
	else
	{
		
		tmp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = tmp;
	}
}