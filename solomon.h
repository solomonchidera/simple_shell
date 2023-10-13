#ifndef SOLOMON_H
#define SOLOMON_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>


/*functions to the starting point*/
char *_strcpy(char *dest, char *src);
void display_prompt1(void);
void display_prompt2(void);
int _strcomp(char *st1, char *st2);
void _puts(char *str);
int _putchar(char c);
char *display_command(void);

#endif

