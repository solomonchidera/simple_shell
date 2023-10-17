#ifndef SCANNER_H
#define SCANNER_H

/**
 * struct source - Just a gaddamn struct.
 * @bu: the input text
 * @busize: size of the input text
 * @cur_pos: absolute char position in source
 */

struct source
{
	char *bu;       /* the input text */
	long busize;       /* size of the input text */
	long  cur_pos;       /* absolute char position in source */
};

/**
 * struct tokens - structure for tokenization.
 * @s: just a random variable.
 * @len_of_text: length of token text
 * @token_text: token text.
 */

struct tokens
{
	struct source *s;

	int len_of_text;
	char *token_text;
};

/* the special EOF token, which indicates the end of input */
extern struct tokens end_of_tok;

struct tokens *tokenizing(struct source *s);
void token_freed(struct tokens *t);
#endif
