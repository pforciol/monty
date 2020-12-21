#include "monty.h"

int monty_dispatch(char **args, stack_t **stack, unsigned int line_nb)
{
	int i = 0;
	instruction_t instructions[] = {
		{"template", template},
		{NULL, NULL}
	};

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

	stack_t **stack = NULL;

	while (getline(&line, &len, fp) != -1)
	{
		/* printf("line = %d\n", line_nb + 1); */
		args = handle_line(line);
		/* debug(args, line_nb); */
		if (args[0] && monty_dispatch(args, stack, line_nb) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		line_nb++;
	}

	return (EXIT_SUCCESS);
}
