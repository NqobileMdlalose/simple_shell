#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "qbshell.h"

/**
 * execute_command - checks if a command exists and executes it
 * @argv: argument vector
 * @err_mesg: error message
 * Return: void
 */
void execute_command(char *argv[], char *err_mesg)
{
    /* Check if the command is a full path (contains '/')*/
    char *path = NULL; 
    char *path_env;
    int is_full_path = qb_strchr(argv[0], '/') != NULL;
	pid_t pid;
	pid = fork();
	
    path_env = getenv("PATH");
	path = qb_strtok(path_env, ":");

    /* If the command is not a full path, check the PATH environment variable*/
    if (!is_full_path)
    {
       
        if (path_env == NULL)
        {
            const char *err_msg = "Error: PATH environment variable not set.\n";
            write(STDERR_FILENO, err_msg, qb_strlen(err_msg));
            return;
        }

        /* Tokenize the PATH variable to search for the command in each directory*/
       
        while (path != NULL)
        {
            char command_path[1024];
            size_t path_len = qb_strlen(path);
            size_t arg_len = qb_strlen(argv[0]);
            size_t command_path_len = path_len + 1 + arg_len + 1; /* +1 for '/', +1 for null terminator*/

            if (command_path_len <= sizeof(command_path))
            {
                qb_strcpy(command_path, path);
                command_path[path_len] = '/';
                qb_strcpy(command_path + path_len + 1, argv[0]);

                /* Check if the command exists in this directory*/
                if (access(command_path, F_OK) == 0)
                {
                    /* Command exists, update the argument vector with the full path*/
                    argv[0] = command_path;
                    break;
                }
            }

            path = qb_strtok(NULL, ":");
        }
    }

    /* Check if the command exists before forking and executing it*/
    if (access(argv[0], F_OK) == -1)
    {
        const char *err_msg = "command not found\n";
        write(STDERR_FILENO, argv[0], qb_strlen(argv[0]));
        write(STDERR_FILENO, ": ", 2);
        write(STDERR_FILENO, err_msg, qb_strlen(err_msg));
        return;
    }

    
    if (pid < 0)
    {
        perror(err_mesg);
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        /* Child process*/
        if (execve(argv[0], argv, environ) == -1)
        {
            perror(err_mesg);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        /* Parent process*/
        if (waitpid(pid, NULL, 0) == -1)
        {
            perror(err_mesg);
            exit(EXIT_FAILURE);
        }
    }
}
