#ifndef _QBSHELL_H
#define _QBSHELL_H
extern char **environ;
void execute_command(char *args[], char *err_mesg);
#endif
