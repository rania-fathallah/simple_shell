#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_ARGS 10

extern char **environ;

/**
 * find_command_path - Find the path of a command.
 * @command: The command to find the path for.
 *
 * Return: The path of the command, or NULL if not found.
 */
char *find_command_path(char *command);

/*
*string functions
*/
int _atoi(char *s);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strpbrk(char *s, char *accept);
unsigned int _strspn(char *s, char *accept);
char *reverse_str(char *s);
char *_strdup(char *str);

#endif
