#include "monty.h"

void free_stack(stack_t *stack)
{
	stack_t *next;

	while (stack != NULL)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
}

int monty_dispatch(char **args, stack_t **stack, unsigned int line_nb)
{
	int i = 0;
	instruction_t instructions[] = {
		{"template", template},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{NULL, NULL}
	};

	if (strcmp(args[0], "push") == 0)
	{
		_push(stack, line_nb, args[1]);
		return (META.error);
	}

	if (strcmp(args[0], "stack") == 0)
	{
		META.state = STACK;
		return (META.error);
	}

	if (strcmp(args[0], "queue") == 0)
	{
		META.state = QUEUE;
		return (META.error);
	}

	while (instructions[i].opcode)
	{
		if (strcmp(args[0], instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_nb);
			return (META.error);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_nb + 1, args[0]);
	META.error = 1;
	return (EXIT_FAILURE);
}

int monty_run(FILE *fp)
{
	char *line = NULL;
	char **args = NULL;
	size_t len = 0;
	unsigned int line_nb = 0;

	stack_t *stack = NULL;

	while (getline(&line, &len, fp) != -1)
	{
		/* printf("line = %d\n", line_nb + 1); */
		args = handle_line(line);
		/* debug(args, line_nb); */
		if (args[0] && monty_dispatch(args, &stack, line_nb) == EXIT_FAILURE)
		{
			free(args);
			free_stack(stack);
			free(line);
			return (EXIT_FAILURE);
		}
		free(args);
		line_nb++;
	}
	free_stack(stack);
	free(line);
	return (EXIT_SUCCESS);
}
