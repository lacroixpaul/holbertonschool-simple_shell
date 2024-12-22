#include "header.h"

/**
* split_line - divide the line into args.
* @line :  pointer to the user input.
* Return: array of characters or NULL if error.
**/

char **split_line(char *line)
{
	int bufsize = 64, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "allocation error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " \t\n");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += 64;
			tokens = _realloc(tokens, bufsize * sizeof(char *),
						(bufsize + 64) * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, " \n");
	}
	tokens[position] = NULL;
	return (tokens);
}
