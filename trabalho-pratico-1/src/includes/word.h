#ifndef __WORD_H__
#define __WORD_H__

typedef struct word * Word;

void wordInit(Word *word);
void wordDelete(Word *word);

int    wordGetLength(Word word);
char * wordGetString(Word word);
void   wordSetString(Word *word, char string[]);
char   wordGetCharAt(Word word, int position);

#endif
