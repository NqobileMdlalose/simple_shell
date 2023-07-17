#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * parse_input - Tokenizes the input line into individual arguments
 * @line: The input line to be parsed.
 * @args: An array of character pointers to store the arguments.
 * @argc: A pointer to an integer to store the number of arguments found.
 */

#define MAX_ARGUMENTS 100

void parse_cmd(const char *line, char *args[], int *argc)
{
    char *token, *command_copy = NULL;
    const char *delimiter = " \n";
    size_t line_length = strlen(line); /*change to qb_strlen()*/
    command_copy = (char *)malloc(line_length + 1);

    if (command_copy == NULL)
    {
        perror("Parse Command Input: Memory allocation error");
        return;
    }
    strcpy(command_copy, line); /* copy input line to command_copy*/
    *argc = 0;
    token = strtok(command_copy, delimiter);

    while (token != NULL && *argc < (MAX_ARGUMENTS - 1))
    {
    args[*argc] = (char *)malloc(strlen(token) + 1); /* change to qb_strlen()*/
    if (args[*argc] == NULL) 
    {
        perror("Parse Command Input: Memory allocation error");
        return;
    }
    strcpy(args[*argc], token); /*change to qb_strcpy()*/
    (*argc)++;
    token = strtok(NULL, delimiter);
    }
    args[*argc] = NULL;
    free(command_copy);
    free(args);
}
