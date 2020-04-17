#include "holberton.h"
/**
 * x - execute commands
 * @av: pointer value
 * @environ: Environment variable.
 * @array: Command.
 * @buff: Buffer.
 * @pt: Exit pointer.
 * @status: Status.
 * Return: Always 0.
 */
int x(char **av, char **environ, char **array, char *buff, int *pt, int status)
{
	pid_t child;
	char errors[50];
	int i = 0, execs = 0;
	struct stat st;

	(void)buff;
	array[0] = list_path(array[0], environ);
	if((stat(array[0], &st) == 0) && (access(array[0], X_OK) == 0))
	{
		child = fork();
		execs++;
	}
	else if (access(array[0], X_OK) == 0)
	{
		sprintf(errors, "%s: %d: %s: Permission denied\n", av[0], execs, array[0]);
		write(STDERR_FILENO, errors, _strlen(errors));
		doublefree(array);
		i = 0;
		while (errors[i])
		{
			errors[i++] = 0;
		}
		*pt = 126;
		return (0);
	}
	else
	{
		sprintf(errors, "%s: %d: %s: not found\n", av[0], execs, array[0]);
		write(STDERR_FILENO, errors, _strlen(errors));
		doublefree(array);
		i = 0;
		while (errors[i])
			{
				errors[i++] = 0;
			}
		*pt = 127;
		return (0);
	}
	if (child == 0)
	{
		if (execve(array[0], array, environ) == -1)
		{
			sprintf(errors, "%s: %d: %s: not found\n", av[0], execs, array[0]);
			write(STDERR_FILENO, errors, _strlen(errors));
			doublefree(array);
			i = 0;
			while (errors[i])
			{
				errors[i++] = 0;
			}
			exit(127);
		}
	}
	else
	{
		wait(&status), doublefree(array);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			*pt = WEXITSTATUS(status);
		}
		return (0);
	}
	return (0);
}
