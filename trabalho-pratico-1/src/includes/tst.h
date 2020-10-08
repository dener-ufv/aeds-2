#ifndef __TST_H__
#define __TST_H__

typedef struct tst_node * Tst;

void tstInit(Tst *root);
void tstInsert(Tst *root, char str[]);

#endif 
