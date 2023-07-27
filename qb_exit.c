#include "qbshell.h"
#include <stdlib.h>

/**
 * qb_exit - handles exit command argument
 * @args: arguments
 * Return: void
 */
void qb_exit(char **args)
{
	int status;

	if (args[0] != NULL)
	{
		if (args[1] != NULL)
		{
			status = qb_atoi(args[1]);
			exit(status);
		}
		else
		{
			exit(EXIT_SUCCESS);
		}
	}
	else
	{
		system("Exit command failure");
		exit(EXIT_FAILURE);
	}
}
