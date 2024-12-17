#include "header.h"

/**
* main - infinite boucle of the shell
* Return: 0 in case of sucess.
**/

int main(void)
{
	char *line = NULL;
	char **args;
	size_t len = 0;
	int status = 1;

	while (status)
	{
		printf("$ ");
		if (read_input(&line, &len) == -1)
		{
			free(line);
			exit(EXIT_FAILURE);
		}
		args = split_line(line);
		if (args[0] != NULL)
		{
			status = execute_command(args);
		}
		free(args);
	}
	free(line);
	return (0);
}

