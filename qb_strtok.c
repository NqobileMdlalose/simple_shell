#include "qbshell.h"
#include <stdio.h>
#include <string.h>

/**
 * qb_strtok - tokenizing the arguments in the shell
 * @str: string
 * @delim: delimiter
 * Return: the tokens
 */

char *qb_strtok(char *str, const char *delim)
{
	static char *next_tok;
	char *token;

	if (str)
		next_tok = str;

	while (*next_tok && strchr(delim, *next_tok))
		next_tok++;
	if (!*next_tok)
		return (NULL);
	token = next_tok;
	while (*next_tok && !strchr(delim, *next_tok))
		next_tok++;
	if (*next_tok)
	{
		*next_tok = '\0';
		next_tok++;
	}
	return (token);
}
