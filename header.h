#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

ssize_t read_input(char **input, size_t *len);
void _env(char *envp[]);
void exit_builtin(char **args, char *input);
int main(int argc, char **argv, char *envp[]);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void execute_command(char **args, char *envp[], char *input);
char **parse_input(char *input);
char *handle_path(char *envp[], char *function_name);
char *_getenv(char *envp[]);


#endif
