#ifndef __WORD_H__
#define __WORD_H__

typedef struct word * Word;

void wordInit(Word *word, char string[]);
void wordDelete(Word *word);

int  wordGetLength(Word word);
char wordGetCharAt(Word word, int position);

#endif
