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
	tok = strtok(av, " \t\n\r\a");
	while (tok)
	{
		size++;
		tok = strtok(NULL, " \t\n\r\a");
	}
	array = _calloc(sizeof(char *), (size + 1));
	if (!array)
	{
		free(buffer);
		return (NULL);
	}
	tok = strtok(buffer, " \t\n\r\a");
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
		tok = strtok(NULL, " \t\n\r\a");
	}
	array[size] = NULL;
	free(buffer);
	return (array);
}
/**
 * check_spaces - Check spaces
 * @buff: buffer
 * Return: 0
 */
int check_spaces(char *buff)
{
	int cnt = 0, spaces = 0;

	while (*(buff + cnt) != '\0')
	{
		if (*(buff + cnt) == 32)
			spaces++;
		cnt++;
	}
	if (_strlen(buff) == (spaces + 1))
	return (0);
	return (1);
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
	char **array = NULL, *buff = NULL;
	size_t len = 0;
	int status = 0, exvalue = 0, *pt = &exvalue;

	(void) ac;
	signal(SIGINT, control);
	while (1)
	{
	isatty(STDIN_FILENO) ? write(STDOUT_FILENO, "#cisfun$ ", 10) : status;
		if (getline(&buff, &len, stdin) != EOF)
		{
			if (check_spaces(buff) == 0)
				continue;
			if (!_strncmp(buff, "exit\n"))
				free(buff), exit(exvalue);
			else if (!_strncmp(buff, "env\n"))
				_environ(environ);
			else if (buff && _strncmp(buff, "\n"))
			{	array = _split(buff);
				if (array[0] != NULL)
				x(av, environ, array, buff, pt, status);
			}
		} else
		{
			isatty(STDIN_FILENO) ? write(STDOUT_FILENO, "\n", 1) : status;
			free(buff), exit(exvalue);
		}
	}
	free(array), free(buff);
	return (exvalue);
}

/**
  * control - function for Ctrl + C
  * @signal: int.
  * Return: nothing.
  */
void control(int signal)
{
	(void)signal;
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, "#cisfun$ ", 10);
}
