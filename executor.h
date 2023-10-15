#ifndef BACK_H
#define BACK_H

#include "node.h"

char *search_path(char *file);
int do_exec_cmd(int argc, char **argv);
int do_simple_command(struct nodes *node);

#endif
