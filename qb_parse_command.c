#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qbshell.h"
#define MAX_ARGUMENTS 100
/**
 * parse_cmd - Tokenizes the input line into individual arguments
 * @line: The input line to be parsed.
 * @args: An array of character pointers to store the arguments.
 * @argc: A pointer to an integer to store the number of arguments found.
 */

void parse_cmd(const char *line, char *args[], int *argc)
{
	char *token, *command_copy = NULL;
	size_t line_length = qb_strlen(line);
	int i;

	if (line_length == 0)
	{
		*argc = 0;
		return;
	}

	command_copy = (char *)malloc(line_length + 1);
	if (command_copy == NULL)
	{
		perror("Parse Command Input: Memory allocation error");
		return;
	}
	qb_strcpy(command_copy, line);
	*argc = 0;
	token = qb_strtok(command_copy, " ");

	while (token != NULL && *argc < (MAX_ARGUMENTS))
	{
		args[*argc] = (char *)malloc(qb_strlen(token) + 1);
		if (args[*argc] == NULL)
		{
			perror("Parse Command Input: Memory allocation error");
			for (i = 0; i < *argc; i++)
			{
				free(args[i]);
			}
			free(command_copy);
			return;
		}
		qb_strcpy(args[*argc], token);
		(*argc)++;
		token = qb_strtok(NULL, " ");
	}
	args[*argc] = NULL;
	free(command_copy);
}
