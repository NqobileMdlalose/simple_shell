#ifndef _QBSHELL_H
#define _QBSHELL_H
<<<<<<< HEAD

/*Header files*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations*/
void parse_cmd(const char *line, char *args[], int *argc)

/*Built-ins*/



#endif /*qbshell.h*/

=======
extern char **environ;
void execute_command(char *args[], char *err_mesg);
#endif
