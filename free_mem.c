#include "qbshell.h"
#include <stdlib.h>
#include <string.h>

/**
 * free_mem - frees allocated memory
 * @args: arguments
 * Returns: 0
 */
void free_mem(*args[])
{
	int i;

	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}
}
