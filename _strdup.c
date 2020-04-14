#include "holberton.h"
/**
 *_strdup - duplicates a string
 *@str: string to dupplicate
 *Return: NULL on error or empty, return duplicated string.
 */

char *_strdup(char *str)
{
	int i;
	int j;
	char *c;

	if (str == 0)
	{
		return (NULL);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		;
	}
	c = malloc(sizeof(char) * (i + 1));
	if (c == 0)
	{
		return (NULL);
	}
	for (j = 0; str[j] != '\0'; j++)
	{
		c[j] = str[j];
	}
	c[j] = '\0';
	return (c);
}

