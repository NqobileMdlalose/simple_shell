#include "main.h"
#include <stdio.h>
#include <string.h>
#define MAX_ARGS 1000
int main() 
{
 char commandInput[100];
    char *args[MAX_ARGS];
    int argc;
    int i;

    printf("Enter a command: ");
    fgets(commandInput, sizeof(commandInput), stdin);
    commandInput[strcspn(commandInput, "\n")] = '\0';
    parse_cmd(commandInput, args, &argc);
    printf("Parsed Arguments:\n");
    for ( i = 0; i < argc; i++) {
        printf("arg[%d]: %s\n", i, args[i]);
    }
    return (0);
}

