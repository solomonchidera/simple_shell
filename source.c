#include <errno.h>
#include "solomon.h"
#include "source.h"

void return_last_char(struct source *s)
{
	if(s->cur_pos < 0)
	{
		return;
	}

	s->cur_pos--;
}


char Nextchar(struct source *s)
{
	char char1;
	if(!s || !s->bu)
	{
		errno = ENODATA;
		return CHARERROR;
	}

	char1 = 0;
	if(s->cur_pos == INIT_SRC_POS)
	{
		s->cur_pos  = -1;
	}
	else
	{
		char1 = s->bu[s->cur_pos];
	}

	if(++s->cur_pos >= s->busize)
	{
		s->cur_pos = s->busize;
		return EOF;
	}

	return s->bu[s->cur_pos];
}


char char_sneekpeek(struct source *s)
{
	if(!s || !s->bu)
	{
		errno = ENODATA;
		return CHARERROR;
	}

	long pos = s->cur_pos;

	if(pos == INIT_SRC_POS)
	{
		pos++;
	}
	pos++;

	if(pos >= s->busize)
	{
		return EOF;
	}

	return s->bu[pos];
}


void skip_whitespace(struct source *s)
{
	char c;

	if(!s || !s->bu)
	{
		return;
	}

	while(((c = char_sneekpeek(s)) != EOF) && (c == ' ' || c == '\t'))
	{
		Nextchar(s);
	}
}
