#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
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
	const char *delimiter = " \n";
	size_t line_length = qb_strlen(line); /*change to qb_strlen()*/
	int i;

	command_copy = (char *)malloc(line_length + 1);
	if (command_copy == NULL)
	{
		perror("Parse Command Input: Memory allocation error");
		return;
	}
	qb_strcpy(command_copy, line); /* copy input line to command_copy*/
	*argc = 0;
	token = strtok(command_copy, delimiter);

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
			free(args);
			free(command_copy);
			return;
		}
		qb_strcpy(args[*argc], token); /*change to qb_strcpy()*/
		(*argc)++;
		token = strtok(NULL, delimiter);
	}
	args[*argc] = NULL;
	free(command_copy);
}
