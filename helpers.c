#include "header.h"

/**
 * _memcpy - copies memory area.
 * @dest: memory area of destination.
 * @n: number of byte to copy.
 * @src : memory area to copy.
 * Return: a pointer to the memory area dest.
 **/

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * *_realloc - reallocates a memory block using malloc and free.
 * @ptr : pointer to the memory previously allocated.
 * @old_size :  is the size, in bytes, of the allocated space for ptr.
 * @new_size : is the new size, in bytes of the new memory block.
 * Return: the pointer to the new memory block of NULL if error.
 **/

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;
	unsigned int min_size;

	if (new_size == old_size)
	{
		return (ptr);
	}
	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
		if (new_ptr == NULL)
			return (NULL);
		min_size = old_size < new_size ? old_size : new_size;
		_memcpy(new_ptr, ptr, min_size);
		free(ptr);
	return (new_ptr);
}

/**
 * _atoi - convert a string to an integer.
 * @s : string to convert.
 * Return: 0 if sucess.
 **/

int _atoi(char *s)
{
int n = 0;
double num = 0;
int sign = 1;

	while (s[n] != '\0')
	{
		if  (s[n] == '-')
		{
			sign = -sign;
		}
		else if (s[n] >= '0' && s[n] <= '9')
		{
			break;
		}
	n++;
	}
	if (s[n] < '0' || s[n] > '9')
	{
		return (0);
	}
		for (; s[n] != '\0'; n++)
		{
			if (s[n] >= '0' && s[n] <= '9')
			{
				num = num * 10 + (s[n] - 48);
			}
			else
			{
			break;
			}
		}
	return (num * sign);
}

/**
 * _isdigit - checks for digit.
 * @str: string to test.
 * Return: 1 if str is digit, Return 0 otherwise.
 **/

int _isdigit(const char *str)
{
	int i = 0;

	if (str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	for (; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		return (0);
	}
	return (1);
}

/**
 * exit_builtin - handle exit.
 * @args : arguments to passed in exit.
 * @line : input line to free after exiting.
 * Return: nothing.
 **/

void exit_builtin(char **args, char *line)
{
	int exit_number = 0;

	free(line);
	if (args[1] != NULL)
	{
		exit_number = _atoi(args[1]);
		free(args);
		exit(exit_number);
	}
	free(args);
	exit(0);
}
