#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
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
