#ifndef MONIAAR_H
#define MONIAAR_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define TOK_DELIM " \t\r\n\a\\"
extern char **environ;
int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
#define my_sizeof(type) "(char *)(&type + 1) - (char *)(&type)"
int main(void);

/* main.c */
void shell_is_interactive(void);
void shell_no_interactive(void);

/* shell_interactive.c */
char *read_line(void);
char **split_line(char *line);
int execute_args(char **args);

/* execute_args */
int new_process(char **args);

/* shell_no_interactive */
char *read_stream(void);

/*---Builtin func---*/
int cd(char **args);
int own_exit(char **args);
int env(char **args);
int assist(char **args);

#endif
