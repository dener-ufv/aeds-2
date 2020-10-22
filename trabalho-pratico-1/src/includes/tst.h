#ifndef __TST_H__
#define __TST_H__

#include "benckmark.h"
#include "word.h"

typedef struct NodoTST *ApNodoTST;
typedef char ChaveTST;
typedef struct NodoTST
{
    ChaveTST chave;
    int FimDeString;
    ApNodoTST Esq, Meio, Dir;
} NodoTST;
typedef ApNodoTST Tst;

void tstInit(Tst *root);
void tstInsert(Tst *root, Word word, Benchmark *bench);
int  tstFind(Tst *root, Word word, Benchmark *bench);
void tstDelete(Tst *root);

#endif 
