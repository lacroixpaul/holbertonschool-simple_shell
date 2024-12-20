#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

ssize_t read_input(char **line, size_t *len);
int execute_command(char **args);
int main(void);
void loop(void);
char **split_line(char *line);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int execute_command(char **args)
int check_command_path(const char *cmd);

#endif
