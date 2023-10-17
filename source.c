#include <errno.h>
#include "solomon.h"
#include "source.h"

/**
 * return_last_char - Funtion to check for the last character
 *
 * @s: variable to use.
 * Return: nothing.
*/
void return_last_char(struct source *s)
{
	if (s->cur_pos < 0)
	{
		return;
	}

	s->cur_pos--;
}

/**
 * Nextchar - Fuction to check next character
 *
 * @s: a struct member
 * Return: s to the current position.
 */
char Nextchar(struct source *s)
{
	char char1;

	if (!s || !s->bu)
	{
		errno = ENODATA;
		return (CHARERROR);
	}

	char1 = 0;

	if (s->cur_pos == INIT_SRC_POS)
	{
		s->cur_pos  = -1;
	}
	else
	{
		char1 = s->bu[s->cur_pos];
	}

	if (++s->cur_pos >= s->busize)
	{
		s->cur_pos = s->busize;
		return (EOF);
	}

	return (s->bu[s->cur_pos]);
}


/**
 * char_sneekpeek - sneek and peek the next character
 * @s: struct member.
 *
 * Return: pointer to the next node.
 */
char char_sneekpeek(struct source *s)
{
	if (!s || !s->bu)
	{
		errno = ENODATA;
		return (CHARERROR);
	}

	long pos = s->cur_pos;

	if (pos == INIT_SRC_POS)
	{
		pos++;
	}
	pos++;

	if (pos >= s->busize)
	{
		return (EOF);
	}

	return (s->bu[pos]);
}

/**
 * skip_whitespace - Function that will skip the whitespace character.
 * @s: struct member.
 *
 * Return: nothing.
 */

void skip_whitespace(struct source *s)
{
	char c;

	if (!s || !s->bu)
	{
		return;
	}

	while (((c = char_sneekpeek(s)) != EOF) && (c == ' ' || c == '\t'))
	{
		Nextchar(s);
	}
}
