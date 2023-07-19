#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "qbshell.h"
#define MAX_ARGUMENT_LENGTH 128
#define MAX_ARGUMENTS 32

int main(void)
{
    char *line = NULL;
    char *args[MAX_ARGUMENTS];
    int argc;
    int read_len;
    char *err_mesg = "Shell:";
    char *command;
    size_t len = MAX_ARGUMENT_LENGTH * MAX_ARGUMENTS;
    const char *prompt = "$ ";

    while (1)
    {
        if (isatty(STDIN_FILENO))
        {
               write(STDOUT_FILENO, prompt, qb_strlen(prompt));
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

        command = args[0];

        switch (command[0])
        {
            case 'a':
                if (qb_strcmp(command, "env") == 0)
                    print_environment();
                break;
            case 'b':
                if (qb_strcmp(command, "exit") == 0)
                    qb_exit(args);
                break;
            default:
                if (argc == 1)
                    execute_command(args, err_mesg);
                break;
        }
    }

    return 0;
}

