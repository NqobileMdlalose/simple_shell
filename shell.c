#include "qbshell.h"
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAX_COMMAND_LENGTH 100
/**
 * handle_non_interactive - handles the non interactive mode
 * @input: input file
 */
void handle_non_interactive(char *input)
{
	int fd = open(input, O_RDONLY);

	if (fd == -1)
	{
		perror("Error opening input file");
		exit(EXIT_FAILURE);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
}
/**
 * run_shell - runs the shell.
 * @argc: argument count
 * @argv: argument vector
 */
void run_shell(int argc, char *argv[])
{
	bool interactive_mode = true;
	char *line = NULL;
	size_t len = 0;
	char *args[MAX_COMMAND_LENGTH];
	char *err_mesg = argv[0];
	const char *prompt = "$ ";
	ssize_t read_len;

	if (!interactive_mode)
	{
		handle_non_interactive(argv[1]);
	}
	while (1)
	{
		if (interactive_mode && isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prompt, qb_strlen(prompt));
		fflush(stdout);
		read_len = getline(&line, &len, stdin);
		if (read_len == -1)
			break;
		if (!interactive_mode && line[read_len - 1] == '\n')
			line[read_len - 1] = '\0';
		argc = 0;
		parse_cmd(line, args, &argc);
		if (strcmp(args[0], "env") == 0)
			print_environment();
		else if (strcmp(args[0], "exit") == 0)
			qb_exit(args);
		else if (argc >= 1)
			execute_command(args, err_mesg);
		if (!interactive_mode)
			break;
	}
	if (!interactive_mode)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
}
