#include "includes/tst_if.h"
#include <stdio.h>

static void atravessaTST(Tst *t, char *buf, int profundidade);
static void ordemTST(Tst *t);



static void atravessaTST(Tst *t, char *buf, int profundidade)
{
    if (*t)
    {
        atravessaTST(&(*t)->Esq, buf, profundidade);
        buf[profundidade] = (*t)->chave;

        if ((*t)->FimDeString == 1)
        {
            buf[profundidade + 1] = '\0';
            printf("%s\n", buf);
        }

        atravessaTST(&(*t)->Meio, buf, profundidade + 1);
        atravessaTST(&(*t)->Dir, buf, profundidade);
    }
}

static void ordemTST(Tst *t)
{
    char buf[MAX_WORD_SIZE+1];
    atravessaTST(t, buf, 0);
}





void tstPrintWords(Tst root) {
    ordemTST(&root);
}
