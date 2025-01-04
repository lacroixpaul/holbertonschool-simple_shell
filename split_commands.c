#include "header.h"

/**
* split_commands - split a string into separate commands.
* @line : input line to analyze.
* Return: an array of strings, each one is a command.
*/

char **split_commands(char *line)
{
	int bufsize = 64, i = 0, j;
	char **commands = malloc(bufsize * sizeof(char *));
	char *command;

	if (!commands)
	{
		fprintf(stderr, "allocation error\n");
		exit(EXIT_FAILURE);
	}
	command = strtok(line, ";");
	while (command != NULL)
	{
		commands[i] = strdup(command);
		if (!commands[i])
		{
			fprintf(stderr, "allocation error\n");
			for (j = 0; j < i; j++)
			{
				free(commands[j]);
			}
			free(commands);
			exit(EXIT_FAILURE);
		}
		i++;
		if (i >= bufsize)
		{
			bufsize += 64;
			commands = _realloc(commands, bufsize * sizeof(char *),
						(bufsize + 64) * sizeof(char *));
			if (!commands)
			{
				fprintf(stderr, "allocation error\n");
				for (j = 0; j < i; j++)
				{
					free(commands[j]);
				}
				free(commands);
				exit(EXIT_FAILURE);
			}
		}
		command = strtok(NULL, ";");
	}
	commands[i] = NULL;
	return (commands);
}
