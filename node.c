#include "solomon.h"
#include "node.h"
#include "parser.h"

/**
 * Newnode - a function to create a new node everytime it gets called
 *
 * @type: varaible to discribe the exact node type
 *
 * Return: struct from type node, hence a new node
 */

struct nodes *Newnode(enum node_type type)
{
	struct nodes *node = malloc(sizeof(struct nodes));

	if (!node)
	{
		return (NULL);
	}

	memset(node, 0, sizeof(struct nodes));
	node->type = type;

	return (node);
}

/**
 * add_childnode - a function to create a baby node for the parent
 *
 * @parent: the main shell proccess
 *
 * @child: a baby from the main exectued shell process
 *
 * Return: Nothing
 */

void add_childnode(struct nodes *parent, struct nodes *child)
{
	if (!parent || !child)
	{
		return;
	}

	if (!parent->firstchild)
	{
		parent->firstchild = child;
	}
	else
	{
		struct nodes *sibling = parent->firstchild;

		while (sibling->nextsibling)
		{
			sibling = sibling->nextsibling;
		}

		sibling->nextsibling = child;
		child->prevsibling = sibling;
	}
	parent->xchildren++;
}

/**
 * set_node_string - a function to make a string of the
 * already made nodes
 *
 * @node: the created child node
 *
 * @val: the node value
 *
 * Return: Nothing
 */

void set_node_string(struct nodes *node, char *val)
{
	node->val_type = VAL_STR;

	if (!val)
	{
		node->val.s = NULL;
	}
	else
	{
		char *val2 = malloc(strlen(val) + 1);

		if (!val2)
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

/**
 * free_nodetree - a function to free the string of nodes
 * that we just created
 *
 * @node: the child node
 *
 * Return: Nothing
 */

void free_nodetree(struct nodes *node)
{
	if (!node)
	{
		return;
	}

	struct nodes *child = node->firstchild;

	while (child)
	{
		struct nodes *next = child->nextsibling;

		free_nodetree(child);
		child = next;
	}

	if (node->val_type == VAL_STR)
	{
		if (node->val.s)
		{
			free(node->val.s);
		}
	}
	free(node);
}
