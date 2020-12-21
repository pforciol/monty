#include "monty.h"

/**
 * handle_input - handles the file given as path, and sets fd
 * @argc: the amount of arguments given to the program
 * @argv: the array of arguments given to the program
 * @fd: the file descriptor to set
 * 
 * Return: 0 on success, otherwise EXIT_FAILURE
 */

int handle_input(int argc, char **argv, FILE **fp)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	*fp = fopen(argv[1], "r");
	if (*fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	return (0);
}

char **handle_line(char *line)
{
	int i = 0, wc = 0, in = 0;
	char **args = NULL;

	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\n' || line[i] == '\t')
			in = 0;
		else if (in == 0)
		{
			in = 1;
			wc++;
		}
		i++;
	}
	printf("wc = %d\n", wc);
	
	args = malloc(sizeof(char *) * (wc + 1));
	if (!args)
		return (NULL);

	i = 0;
	while ((args[i] = strtok(i == 0 ? line : NULL, " \n\t")))
		i++;

	return (args);
}

void free_args(char **args)
{
	int i = 0;

	while (args[i])
	{
		free(args[i]);
		i++;
	}
}
