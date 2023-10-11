#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>

#define MAX_PATH_LENGTH 1024

/**
 * strcut built - contains a builtin string and some related functions
 *
 * @flag: pointer to the built in command flag
 *
 * @fu: common function
 */

typedef struct built built_t;

struct built
{
        char *flag;
        int(*fu)(details*);
}built_t;


/**
 * struct common_arg - contains arguments to be passed into a function
 *
 * @l_errorcount: error counting
 *
 * @read_fd: the fd to be read from the input line
 */

typedef struct common_arg details;

struct common_arg
{
        unsigned int l_errorcount;
        int read_fd;
        char *fdname;
        char *arg;
        char *argv;
        char *path;
        int argc;
}details;

void user_command(char *commands, size_t size);
char **split(char *string, char *del);
char strdup_(const char *string);
int check_del(char ch, char *del);
char strdup_(const char *string);
char *find_command_in_path(const char *command);
char *locateChar(char *string, char c);
int sloop(details *n, char **av);
int find_(details *n);
void _exit(int status);
void _puts(char *str);
void set_details(details *a, char **av);
void display_prompt(void);
void exec_command(const char *commands);
int _putchar(char c);
int _strcomp(char *st1, char *st2);
int _strlen(char *string);


#endif
