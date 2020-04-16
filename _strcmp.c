#include "holberton.h"
/**
  * _strncmp - compares two strings.
  * @s1: first string.
  * @s2: second string.
  * Return: j
  */
int _strncmp(char *s1, char *s2)
{
	int i, j;

	i = 0;
	while (s1[i] != 0)
	{
		j = s1[i] - s2[i];
		if (j != 0)
			return (j);
		i++;
	}
	return (j);
}
