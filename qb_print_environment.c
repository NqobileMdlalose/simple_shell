#include "qbshell.h"
#include <unistd.h>

/*
* print_environment -  Prints the current environment.
*/

void print_environment(void)
{
char **envir = environ;

while (*envir != NULL)
{
	    size_t len = qb_strlen(*envir);

	write(STDOUT_FILENO, *envir, len);
	write(STDOUT_FILENO, "\n", 1);
envir++;
}
}
