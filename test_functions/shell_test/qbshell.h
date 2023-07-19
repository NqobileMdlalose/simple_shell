#ifndef _QBSHELL_H
#define _QBSHELL_H
extern char **environ;
void run_shell(void);
void qb_exit(char **args);
void parse_cmd(const char *line, char *args[], int *argc);
int qb_strcmp(const char *str1, const char *str2);
void execute_command(char *args[], char *err_mesg);
char *qb_strcpy(char *dest, const char *src);
int qb_strlen(const char *string);
void print_environment(void);
int qb_atoi(const char *str);
#endif
