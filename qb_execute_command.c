#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "qbshell.h"
/**
 * execute_command - checks if a command exists
 * @argv: argument vector
 * @err_mesg: error messege
 * Return: void
 */

void execute_command(char *argv[], char *err_mesg)
{
	pid_t pid;
	int status;

	if (qb_strcmp(argv[0], "ls") == 0)
	{
		argv[0] = "/bin/ls";
	}
	/** The function checks if the command exists using access **/
	if (access(argv[0], F_OK) == -1)
	{
		perror(err_mesg);
		return;
	}
	/** forks a new process **/
	pid = fork();
	if (pid < 0)
	{
		perror(err_mesg);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/** Child process **/
		execve(argv[0], argv, environ);
		perror(err_mesg);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror(err_mesg);
			exit(EXIT_FAILURE);
		}
	}
}
