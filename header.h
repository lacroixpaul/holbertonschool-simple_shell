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
int execute_command(char **args, char *argv[], char *envp[]);
int main(int argc, char *argv[], char *envp[]);
void loop(char *argv[], char *envp[]);
char **split_line(char *line);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *find_executable(char *command, char *envp[]);

#endif
