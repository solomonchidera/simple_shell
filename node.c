#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include "solomon.h"
#include "node.h"
#include "parser.h"


struct nodes *Newnode(enum node_type type)
{
	struct nodes *node = malloc(sizeof(struct nodes));

	if(!node)
	{
		return NULL;
	}

	memset(node, 0, sizeof(struct nodes));
	node->type = type;

	return node;
}


void add_childnode(struct nodes *parent, struct nodes *child)
{
	if(!parent || !child)
	{
		return;
	}

	if(!parent->firstchild)
	{
		parent->firstchild = child;
	}
	else
	{
		struct nodes *sibling = parent->firstchild;

		while(sibling->nextsibling)
		{
			sibling = sibling->nextsibling;
		}

		sibling->nextsibling = child;
		child->prevsibling = sibling;
	}
	parent->xchildren++;
}


void set_node_string(struct nodes *node, char *val)
{
	node->val_type = VAL_STR;

	if(!val)
	{
		node->val.s = NULL;
	}
	else
	{
		char *val2 = malloc(strlen(val)+1);

		if(!val2)
		{
			node->val.s = NULL;
		}
		else
		{
			strcpy(val2, val);
			node->val.s = val2;
		}
	}
}


void free_nodetree(struct nodes *node)
{
	if(!node)
	{
		return;
	}

	struct nodes *child = node->firstchild;

	while(child)
	{
		struct nodes *next = child->nextsibling;
		free_nodetree(child);
		child = next;
	}

	if(node->val_type == VAL_STR)
	{
		if(node->val.s)
		{
			free(node->val.s);
		}
	}
	free(node);
}
