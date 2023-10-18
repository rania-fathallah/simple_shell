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
#include <ctype.h>

#define MAX_ARGS 64

extern char **environ;

/**
 * find_command_path - Find the path of a command.
 * @command: The command to find the path for.
 *
 * Return: The path of the command, or NULL if not found.
 */
char *find_command_path(char *command);

/**
 * trim_whitespace - Trims leading and trailing whitespaces from a string.
 * @str: Input string.
 *
 * Return: Trimmed string.
 */
char *trim_whitespace(char *str);

#endif
