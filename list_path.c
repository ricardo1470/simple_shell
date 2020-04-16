#include "holberton.h"

/**
 * list_path - List the path
 *
 *@array: array
 *
 *@environ: environ.
 *
 * Return: Always 0.
 */
char *list_path(char array[], char *environ[])
{
	int i = 0, str = 69;
	char *tmp = NULL, *token = NULL;
	static char *buf;
	struct stat st;

	for (i = 0; environ[i] != NULL; i++)
		if (strncmp(environ[i], "PATH=", 4) == 0)
			break;
	tmp = _strdup(environ[i]);
	token = strtok(tmp, ":");
	for (i = 0; token != NULL; i++)
	{
		buf = malloc((_strlen(token) + _strlen(array) + 2) * sizeof(char));
		if (buf == NULL)
		{
			free(buf);
			return (array);

		}
		_strcpy(buf, token);
		_strcat(buf, "/");
		_strcat(buf, array);
		str = stat(buf, &st);
		if (str == 0)
			return (buf);
		free(buf);
		token = strtok(NULL, ":");
	}
	free(tmp);
	return (array);
}

