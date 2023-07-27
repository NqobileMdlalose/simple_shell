#include "qbshell.h"
#include <string.h>
#define MAX_COMMAND_LENGTH 1024
/**
 * parse_cmd - tokenize inputs
 * @line: argument 1
 * @args: argument 2
 * @argc: argument 3
 */
void parse_cmd(char *line, char *args[], int *argc)
{
	char *token;

	*argc = 0;
	token = qb_strtok(line, " ");
	while (token != NULL && *argc < MAX_COMMAND_LENGTH - 1)
	{
		args[*argc] = token;
		(*argc)++;
		token = qb_strtok(NULL, " ");
	}
	args[*argc] = NULL;
}
