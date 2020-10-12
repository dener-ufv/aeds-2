#ifndef __TST_H__
#define __TST_H__

#include "benckmark.h"
#include "word.h"

typedef struct tst_node * Tst;

void tstInit(Tst *root);
void tstInsert(Tst *root, Word word, Benchmark *bench);
void tstDelete(Tst *root);

#endif 
