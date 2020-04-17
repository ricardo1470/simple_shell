#include "holberton.h"
/**
 * x - execute commands
 * @av: pointer value
 * @environ: Environment variable.
 * @aray: Command.
 * @buff: Buffer.
 * @pt: Exit pointer.
 * @status: Status.
 * Return: Always 0.
 */
int x(char **av, char **environ, char **aray, char *buff, int *pt, int status)
{
pid_t child;
char errors[50];
int i = 0, execs = 0;

child = fork(), execs++;
if (child == 0)
{
	aray[0] = list_path(aray[0], environ);
	if (execve(aray[0], aray, environ) == -1)
	{	sprintf(errors, "%s: %d: %s: not found\n", av[0], execs, aray[0]);
		write(STDERR_FILENO, errors, _strlen(errors)), free(buff);
		doublefree(aray);
		i = 0;
		while (errors[i])
			errors[i++] = 0;
		exit(127);
	}
} else
	wait(&status), doublefree(aray);
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
	*pt = WEXITSTATUS(status);
	return (0);
}
