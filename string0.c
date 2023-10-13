#include "main.h"
/**
 *_atoi - for copy  elements of array
 *description: this function for copy elemnts of src array
 *@s: the char  pointer for an array
 *Return: int  success
 */

int _atoi(char *s)
{
	int x = 1;
	unsigned int y = 0;

	do {
		if (*s == '-')
		{
			x = x * (-1);
		}
		else if (*s >= 48 && *s <= 57)
		{
			y = (y * 10) + (*s - 48);
		}
		else if (y > 0)    /*as an ascii point not 0 */
			break;
	} while (*s++);

	return (x * y);
}
/**
 *_strlen - for reset value swap
 *description: this function for charachter check
 *@s: the int pointer for a string location
 *Return: x success
 */

int _strlen(char *s)
{
	int x;

	for (x = 0; *s != '\0'; x++)
	{
		s++;
	}
		return (x);
}
/**
 *_strcmp - for cpy the string
 *description: this function for conactes two strings
 *@s1: the int pointer for a first string
 *@s2: the pointer for second string
 *Return: int sucess
 */
int _strcmp(char *s1, char *s2)
{
	int x;

	x = 0;
	while (*s1)
	{
		if (*s1 != *s2)
		{
			x = ((int)*s1 - 48) - ((int)*s2 - 48);
			break;
		}
		s1++;
		s2++;
	}
	return (x);
}
/**
 *_strpbrk - for search  of string
 *description: this function for searching the stringfor any bytes
 *@s: the string to be printed
 *@accept: the location of the sub string
 *Return: char  succes
 */
char *_strpbrk(char *s, char *accept)
{
	int x;
	int y;
	char *p;

	for (x = 0; s[x] != '\0'; x++)
	{
		for (y = 0; accept[y] != '\0'; y++)
		{
			if (accept[y] == s[x])
			{
				p = &s[x];
				return (p);
			}
		}
	}
	return (0);
}
/**
 *_strspn - for length of string
 *description: this function for locating char in string
 *@s: the string to be printed
 *@accept: the location of the sub string
 *Return: unsigned int  succes
 */
unsigned int _strspn(char *s, char *accept)
{
	int x;
	int y;

	for (x = 0; s[x] != '\0'; x++)
	{
		for (y = 0; accept[y] != s[x]; y++)
		{
			if (accept[y] == '\0')
				return (x);
		}
	}
	return (x);

}
