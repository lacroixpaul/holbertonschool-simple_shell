#include "header.h"

/**
* loop - infinite boucle of the shell
* Return: void.
**/

void loop(void)
{
	char *line = NULL;
	char **args;
	size_t len = 0;
	int status = 1;

	while (status)
	{
		printf("#cisfun$ ");
		if (read_input(&line, &len) == -1)
		{
			free(line);
			exit(EXIT_FAILURE);
		}
		args = split_line(line);
		if (args[0] != NULL)
		{
			if (strcmp(args[0], "exit") == 0)
			{
				status = 0;
			}
			else
			{
				status = execute_command(args);
			}
		}
		free(args);
	}
	free(line);
}
