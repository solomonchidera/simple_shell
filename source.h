#ifndef SOURCE_H
#define SOURCE_H

#define EOF (-1)
#define CHARERROR (0)

#define INIT_SRC_POS    (-2)

struct source
{
    char *bu;       /* the input text */
    long busize;       /* size of the input text */
    long  cur_pos;       /* absolute char position in source */
};

char Nextchar(struct source *s);
void return_last_char(struct source *s);
char char_sneekpeek(struct source *s);
void skip_whitespace(struct source *s);
#endif
