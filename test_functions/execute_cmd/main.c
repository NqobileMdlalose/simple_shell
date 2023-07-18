#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "qbshell.h"

int main()
{
    char *command[] = {"ls", "-l", NULL};
    char err_mesg[100];

    execute_command(command, err_mesg);

    return 0;
}
