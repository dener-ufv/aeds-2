#ifndef __WORD_H__
#define __WORD_H__

typedef struct word * Word;

#define MAX_WORD_SIZE 255

void wordInit(Word *word);
void wordDelete(Word *word);

int    wordEquals(Word w1, Word w2);
int    wordGetLength(Word word);
char * wordGetString(Word word);
void   wordSetString(Word *word, char string[]);
char   wordGetCharAt(Word word, int position);

#endif
