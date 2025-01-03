#include "header.h"

/**
* split_commands - split a string into separate commands.
* @line : input line to analyze.
* Return: an array of strings, each one is a command.
*/

char **split_commands(char *line)
{
	int bufsize = 64, i = 0;
	char **commands = malloc(bufsize * sizeof(char *));
	char *command;

	if (!commands)
	{
		fprintf(stderr, "allocation error\n");
		exit(EXIT_FAILURE);
	}
	command = strtok(line, ";\n");
	while (command != NULL)
	{
		commands[i] = strdup(command);
		i++;
		if (i >= bufsize)
		{
			bufsize += 64;
			commands = _realloc(commands, bufsize * sizeof(char *),
						(bufsize + 64) * sizeof(char *));
			if (!commands)
			{
				fprintf(stderr, "allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		command = strtok(NULL, ";\n");
	}
	commands[i] = NULL;
	return (commands);
}
