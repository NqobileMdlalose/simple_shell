#ifndef _QBSHELL_H
#define _QBSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stddef.h>
extern char **environ;

char *qb_strchr(char *str, int chr);
char *qb_strtok(char *str, const char *delim);
void free_mem(char *args[]);
void run_shell(int argc, char *argv[]);
void handle_non_interactive(char *argv[], int argc);
void qb_exit(char **args);
void parse_cmd(const char *line, char *args[], int *argc);
int qb_strcmp(const char *str1, const char *str2);
void execute_command(char *args[], char *err_mesg);
char *qb_strcpy(char *dest, const char *src);
int qb_strlen(const char *string);
void print_environment(void);
int qb_atoi(const char *str);
int qb_getline(char **line, size_t *len, FILE *stream);
#endif
