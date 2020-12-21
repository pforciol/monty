#include "monty.h"

void debug(char **args, int line_nb)
{
	int i = 0;

	printf("line[%d] = ", line_nb + 1);
	while (args && args[i])
	{
		printf("[%s] ", args[i]);
		i++;
	}
	printf("\n");
}
