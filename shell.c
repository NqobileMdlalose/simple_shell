#include "qbshell.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAX_COMMAND_LENGTH 100
/**
 * handle_non_interactive - handles the non interactive mode
 * @argv: argument vector
 * @argc: argc count
 */
void handle_non_interactive(char *argv[], int argc)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read_len;
	char *err_mesg = argv[0];
	char *args[MAX_COMMAND_LENGTH];

	errno = ENOENT;
	while ((read_len = getline(&line, &len, stdin)) != 1)
	{
		if (line[read_len - 1] == '\n')
			line[read_len - 1] = '\0';
		parse_cmd(line, args, &argc);
		if (qb_strcmp(args[0], "env") == 0)
			print_environment();
		if (qb_strcmp(args[0], "exit") == 0 && argc == 2)
			qb_exit(args);
		if (argc >= 1 && qb_strcmp(args[0], "env") != 0)
			execute_command(args, err_mesg);
		free(line);
	}
}
/**
 * run_shell - runs the shell.
 * @argc: argument count
 * @argv: argument vector
 */
void run_shell(int argc, char *argv[])
{
	char *line = NULL;
	size_t len = 0;
	char *args[MAX_COMMAND_LENGTH];
	char *err_mesg = argv[0];
	const char *prompt = "$ ";
	ssize_t read_len;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, prompt, qb_strlen(prompt));
			fflush(stdout);
		}
		read_len = getline(&line, &len, stdin);
		if (read_len == -1)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		if (line[read_len - 1] == '\n')
			line[read_len - 1] = '\0';
		argc = 0;
		parse_cmd(line, args, &argc);
		if (qb_strcmp(args[0], "env") == 0)
			print_environment();
		if (qb_strcmp(args[0], "exit") == 0 && argc == 2)
			qb_exit(args);
		if (argc >= 1 && (qb_strcmp(args[0], "env") != 0))
			execute_command(args, err_mesg);
	}
}
