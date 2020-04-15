#include "holberton.h"
/**
 * doublefree - free double pointer
 * @array: pointer to free
 */
void doublefree(char **array)
{
	int i = 0;

	while (array[i])
	{
		free(array[i]);
		i++;
	}
	if (array)
		free(array);
}
/**
 * _split - Entry point.
 *@av: pointer value
 * Return: Always 0 (Success)
 */
char **_split(char *av)
{
	char *tok = NULL;
	char *buffer = NULL;
	size_t size = 0;
	char **array = NULL;

	buffer = malloc(sizeof(char) * _strlen(av) + 1);
	if (!buffer)
		return (NULL);
	_strcpy(buffer, av);
	tok = strtok(av, " \t\n\r");
	while (tok)
	{
		size++;
		tok = strtok(NULL, " \t\n\r");
	}
	array = _calloc(sizeof(char *), (size + 1));
	if (!array)
	{
		free(buffer);
		return (NULL);
	}
	tok = strtok(buffer, " \t\n\r");
	size = 0;
	while (tok)
	{
		array[size] = malloc(sizeof(char) * _strlen(tok) + 1);
		if (!array[size])
		{
			free(buffer);
			doublefree(array);
			return (NULL);
		}
		_strcpy(array[size++], tok);
		tok = strtok(NULL, " \t\n\r");
	}
	free(buffer);
	return (array);
}
/**
 * main - simple shell
 * @ac: value
 * @av: pointer value
 * @environ: Environment variable.
 * Return: 0
 */
int main(int ac, char **av, char *environ[])
{
	pid_t child;
	char **array = NULL, *buff = NULL, errors[50];
	size_t len = 0;
	int status = 0, execs = 0;

	(void) ac;
	while (1)
	{
	isatty(STDIN_FILENO) ? write(STDOUT_FILENO, "#cisfun$ ", 10) : status;
		if (getline(&buff, &len, stdin) != EOF)
		{
			if (!_strcmp(buff, "exit\n"))
			{	free(buff);
				exit(EXIT_SUCCESS);
			}
			else if (buff && _strcmp(buff, "\n") && _strcmp(buff, " "))
			{	array = _split(buff);
				if (array[0] == NULL)
					break;
				child = fork();
				execs++;
				if (child == 0)
				{
					array[0] = list_path(array[0], environ);
					if (execve(array[0], array, environ) == -1)
					{	sprintf(errors, "%s: %d: %s: not found\n", av[0], execs, array[0]);
						write(STDERR_FILENO, errors, _strlen(errors)), free(buff);
						doublefree(array);
						exit(128);
					}
				} else
					wait(&status);
					doublefree(array);	}
		} else
		{
			isatty(STDIN_FILENO) ? write(STDOUT_FILENO, "\n", 1) : status;
			free(buff);
			exit(EXIT_SUCCESS);
		}
	} return (0);
}
