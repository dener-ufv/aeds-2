#include "includes/word.h"
#include <stdlib.h>
#include <string.h>

struct word {
    char *str;
    int len;
};

void wordInit(Word *word) {
    *word = (Word) malloc(sizeof **word);
    (*word)->len = 0;
    (*word)->str = NULL;
}

void wordDelete(Word *word) {
    free(*word);
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
