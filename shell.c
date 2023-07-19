#include "qbshell.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAX_COMMAND_LENGTH 100

/**
 * run_shell - runs the shell.
 */
void run_shell(void)
{
	int argc;
	char *line = NULL;
	size_t len = 0;
	ssize_t read_len;
	char *args[MAX_COMMAND_LENGTH];
	char *err_mesg = "Shell";
	const char *prompt = "$ ";
	const char *new_prompt = "\n";

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prompt, qb_strlen(prompt));
		fflush(stdout);

		read_len = getline(&line, &len, stdin);
		if (read_len == -1)
		{
			free(line);
			write(STDOUT_FILENO, new_prompt, qb_strlen(new_prompt));
			exit(EXIT_SUCCESS);
		}

		if (line[read_len - 1] == '\n')
			line[read_len - 1] = '\0';

		argc = 0;
		parse_cmd(line, args, &argc);

		if (strcmp(args[0], "env") == 0)
			print_environment();
		else if (strcmp(args[0], "exit") == 0)
			qb_exit(args);
		else if (argc >= 1)
			execute_command(args, err_mesg);
	}
}
