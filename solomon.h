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
#include "parser.h"
#include "node.h"

/*functions to the starting point*/
char *_strcpy(char *dest, char *src);
void display_prompt1(void);
void display_prompt2(void);
int _strcomp(char *st1, char *st2);
void _puts(char *str);
int _putchar(char c);
char *display_command(void);
/*functions to handle the command and search for the path*/
char *search_path(char *file);
int do_exec_cmd(int argc, char **argv);
int do_simple_command(struct nodes *node);
/*AST handling*/
struct nodes *Newnode(enum node_type type);
void add_childnode(struct nodes *parent, struct nodes *baby);
void free_nodetree(struct nodes *node);
void set_node_string(struct nodes *node, char *val);
/*a function to handle the parsing and tokenizing part*/
#include "source.h"
int parse_and_execute(struct source *src);
#endif

