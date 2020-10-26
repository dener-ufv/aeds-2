/*
  Grupo Divididos
  3869 - Fábio Trindade Ramos
  3872 - Dener Vieira Ribeiro
  2665 - Lucas Takeshi Moreira Chang
  3889 - Igor de Melo Alves
*/

#include "includes/word.h"
#include <stdlib.h>
#include <string.h>

struct word {
    char *str;
    int len;
};

void wordInit(Word *word) {
    *word = (Word) malloc(sizeof(struct word));
    (*word)->len = 0;
    (*word)->str = NULL;
}

void wordDelete(Word *word) {
    free((*word)->str);
    (*word)->len = 0;
    (*word)->str = NULL;
    free(*word);
    *word = NULL;
}

int wordEquals(Word w1, Word w2) {
    return strcmp(w1->str, w2->str) == 0;
}

int  wordGetLength(Word word) {
    return word->len;
}

char * wordGetString(Word word) {
    return word->str;
}

void   wordSetString(Word *word, char string[]) {
    if((*word)->len > 0) free((*word)->str);
    int len = strlen(string);
    (*word)->str = (char*) malloc((len+1) * sizeof(char));
    strcpy((*word)->str, string);
    (*word)->len = len;
}

char wordGetCharAt(Word word, int position) {
    return position >= word->len ? '\0' : word->str[position];
}
