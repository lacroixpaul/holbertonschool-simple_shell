#include "header.h"

/**
* split_line - divide the line into args.
* @line :  pointer to the user input.
* Return: array of characters or NULL if error.
**/

char **split_line(char *line)
{
	int bufsize = 64, position = 0;
	char **tkns = malloc(bufsize * sizeof(char *));
	char *tkn;

	if (!tkns)
	{
		fprintf(stderr, "allocation error\n");
		exit(EXIT_FAILURE);
	}
	tkn = strtok(line, " \t\n");
	while (tkn != NULL)
	{
		tkns[position] = tkn;
		position++;

		if (position >= bufsize)
		{
			bufsize += 64;
			tkns = _realloc(tkns, bufsize * sizeof(char *),
						(bufsize + 64) * sizeof(char *));
			if (!tkns)
			{
				fprintf(stderr, "allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		tkn = strtok(NULL, " \n");
	}
	tkns[position] = NULL;
	return (tkns);
}
