#include <stdio.h>
#include "includes/patricia.h"
#include "includes/patricia_if.h"
#include "includes/benckmark.h"

int main() {
    Benchmark benchPatricia;
    Word w;
    wordInit(&w);

    Patricia tree;
    patriciaInit(&tree);
    benchmarkInit(&benchPatricia);

    int N = 5;
    char* list[] = {"amor", "amarelo", "baleia", "amar", "bala"};

    int i;
    for(i=0; i<N; i++) {
        wordSetString(&w, list[i]);
        patriciaInsert(&tree, w, &benchPatricia);
    }

    benchmarkStartTimer(&benchPatricia);
    patriciaPrintWords(tree);
    benchmarkStopTimer(&benchPatricia);


    printf("Tempo de execução patricia:%lf \n",benchmarkGetTime(benchPatricia) );
    printf("Comparações Patricia:%d \n",benchmarkGetComparations(benchPatricia));


    return 0;
}
