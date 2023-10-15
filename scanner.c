#include "solomon.h"
#include "scanner.h"
#include "source.h"

char *t_buffer = NULL;
int   t_bufsize  = 0;
int   t_bufindex = -1;

/* special token to indicate end of input */
struct tokens end_of_tok = 
{
	.len_of_text = 0,
};


void addto_buffer(char ch)
{
	char *temp;
	t_buffer[t_bufindex++] = ch;

	if(t_bufindex >= t_bufsize)
	{
		temp = realloc(t_buffer, t_bufsize*2);

		if(!temp)
		{
			errno = ENOMEM;
			return;
		}

		t_buffer = temp;
		t_bufsize *= 2;
	}
}


struct tokens *make_token(char *st)
{
	struct tokens *tk = malloc(sizeof(struct tokens));

	if(!tk)
	{
		return NULL;
	}

	memset(tk, 0, sizeof(struct tokens));
	tk->len_of_text = strlen(st);

	char *nst = malloc(tk->len_of_text+1);

	if(!nst)
	{
		free(tk);
		return NULL;
	}

	strcpy(nst, st);
	tk->token_text = nst;

	return tk;
}


void token_freed(struct tokens *t)
{
	if(t->token_text)
	{
		free(t->token_text);
	}
	free(t);
}


struct tokens *tokenizing(struct source *s)
{
	int loopend = 0;

	if(!s || !s->bu || !s->busize)
	{
		errno = ENODATA;
		return &end_of_tok;
	}

	if(!t_buffer)
	{
		t_bufsize = 1024;
		t_buffer = malloc(t_bufsize);
		if(!t_buffer)
		{
			errno = ENOMEM;
			return &end_of_tok;
		}
	}

	t_bufindex = 0;
	t_buffer[0] = '\0';

	char n = Nextchar(s);

	if(n == CHARERROR || n == EOF)
	{
		return &end_of_tok;
	}

	do
	{
		switch(n)
		{
			case ' ':
			case '\t':
				if(t_bufindex > 0)
				{
					loopend = 1;
				}
				break;

			case '\n':
				if(t_bufindex > 0)
				{
					return_last_char(s);
				}
				else
				{
					addto_buffer(n);
				}
				loopend = 1;
				break;

			default:
				addto_buffer(n);
				break;
		}

		if(loopend)
		{
			break;
		}

	} while((n = Nextchar(s)) != EOF);

	if(t_bufindex == 0)
	{
		return &end_of_tok;
	}

	if(t_bufindex >= t_bufsize)
	{
		t_bufindex--;
	}
	t_buffer[t_bufindex] = '\0';

	struct tokens *tk = make_token(t_buffer);
	if(!tk)
	{
		fprintf(stderr, "error: failed to alloc buffer: %s\n", strerror(errno));
		return &end_of_tok;
	}

	tk->s = s;
	return tk;
}
