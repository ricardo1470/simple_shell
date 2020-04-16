#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

/**
 * struct Pf_func - format
 * _printf- print function
 * @op: pointer
 * @f: function pointer
*/
typedef struct Pf_func
{
	char *op;
	int (*f)(va_list);
} print_fun;

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;


int _putchar(char c);
char **_split(char *av);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strncmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
void *_calloc(unsigned int nmemb, unsigned int size);
int (*get_op_func(const char *s, int pos))(va_list);
char *list_path(char array[], char *environ[]);
char *_strdup(char *str);
char *_getenv(const char *name);
int _environ(char *environ[]);
void control(int signal);
int x(char **av, char **environ, char **array, char *buff, int *pt, int status);
void doublefree(char **array);



#endif /* HOLBERTON_H */
