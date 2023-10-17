#ifndef SCANNER_H
#define SCANNER_H

struct tokens
{
	struct source *s;       /* source of input */
	int len_of_text;            /* length of token text */
	char *token_text;               /* token text */
};

/* the special EOF token, which indicates the end of input */
extern struct tokens end_of_tok;

struct tokens *tokenizing(struct source *s);
void token_freed(struct tokens *t);
#endif
