#include "header.h"

/**
* split_line - divide the line into args.
* @line :  pointer to the user input.
* Return: array of characters or NULL if error.
**/

char **split_line(char *line)
{
	int buffersize = 64, position = 0;
	char **tokens = malloc(buffersize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "allocation error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " \n");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= buffersize)
		{
			buffersize += 64;
			tokens = realloc(tokens, buffersize * sizeof(char *));
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
