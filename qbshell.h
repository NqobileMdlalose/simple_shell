#ifndef _QBSHELL_H
#define _QBSHELL_H
extern char **environ;

void qb_exit(char **args);
void parse_cmd(const char *line, char *args[], int *argc);
int qb_strcmp(const char *str1, const char *str2);
void execute_command(char *args[], char *err_mesg);
#endif
