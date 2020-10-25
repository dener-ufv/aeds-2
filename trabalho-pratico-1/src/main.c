#include <stdio.h>
#include "includes/patricia.h"
#include "includes/patricia_if.h"
#include "includes/benckmark.h"
#include "includes/tst.h"
#include "includes/tst_if.h"

int main() {
    Benchmark benchPatricia;
    Benchmark benchTst;
    Word w;
    Patricia tree;
    Tst t;

    benchmarkInit(&benchTst);
    benchmarkInit(&benchPatricia);
    wordInit(&w);
    patriciaInit(&tree);
    tstInit(&t);

    int N = 5;
    char* list[] = {"aba", "aca", "ada", "aea", "aba"};

    int i;

    printf("\n PATRICIA \n\n");

    benchmarkStartTimer(&benchPatricia);
    for(i=0; i<N; i++) {
        wordSetString(&w, list[i]);
        patriciaInsert(&tree, w, &benchPatricia);
    }
    benchmarkStopTimer(&benchPatricia);
    patriciaPrintWords(tree);

    printf("\n\n TST\n\n");

    benchmarkStartTimer(&benchTst);
    for(i=0; i<N; i++) {
        wordSetString(&w, list[i]);
        tstInsert(&t, w, &benchTst);
    }
    benchmarkStopTimer(&benchTst);
    tstPrintWords(t);


    patriciaDelete(&tree);
    tstDelete(&t);
    wordDelete(&w);

    return 0;
}
