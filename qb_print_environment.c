#include "qbshell.h"
#include <unistd.h>

/**
 * print_environment -  Prints the current environment.
 * Return: void
 */
void print_environment(void)
{
	char **envir = environ;
	size_t len;

	while (*envir != NULL)
	{
		len = qb_strlen(*envir);
		write(STDOUT_FILENO, *envir, len);
		write(STDOUT_FILENO, "\n", 1);
		envir++;
	}
}
