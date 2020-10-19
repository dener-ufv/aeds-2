#ifndef __PATRICIA_H__
#define __PATRICIA_H__

#include "benckmark.h"
#include "word.h"

typedef struct patricia_node * Patricia;

void patriciaInit(Patricia *root);
int  patriciaInsert(Patricia *root, Word word, Benchmark *bench);
int  patriciaFind(Patricia *root, Word word, Benchmark *bench);
void patriciaDelete(Patricia *root);

Patricia patriciaGetLeft(Patricia root);
Patricia patriciaGetRight(Patricia root);
int      patriciaIsLeaf(Patricia root);
Word     patriciaGetWord(Patricia root);

#endif
