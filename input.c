#include "header.h"

/**
* read_input - read the user input.
* @line : double pointer to store the user input.
* @len : pointer to thesize of the buffer.
* Return: the number of reader characters or -1 if error.
**/

ssize_t read_input(char **line, size_t *len)
{
	ssize_t read;

	if (*line == NULL)
		*len = 0;

	read = getline(line, len, stdin);
	return (read);
}
