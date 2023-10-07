#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void user_command(char *commands, size_t size);
void display_prompt(void);
void exec_command(const char *commands);
#endif
