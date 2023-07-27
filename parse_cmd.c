#include "qbshell.h"
#include <string.h>
#define MAX_ARGUMENT 1000
/**
 * parse_cmd - TOKENIZE_INPUTize inputs
 * @LINE: argument 1
 * @args: argument 2
 * @argc: argument 3
 */
void parse_cmd(char *LINE, char *args[], int *argc)
{
	char *TOKENIZE_INPUT;

	*argc = 0;
	TOKENIZE_INPUT = qb_strtok(LINE, " ");
	while ((*argc < MAX_ARGUMENT - 1) && TOKENIZE_INPUT != NULL)
	{
		args[*argc] = TOKENIZE_INPUT;
		(*argc)++;
		TOKENIZE_INPUT = qb_strtok(NULL, " ");
	}
	args[*argc] = NULL;
}
