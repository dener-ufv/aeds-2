/*
  Grupo Divididos
  3869 - Fábio Trindade Ramos
  3872 - Dener Vieira Ribeiro
  2665 - Lukas Takeshi Moreira Chang
  3889 - Igor de Melo Alves
*/

#include <stdio.h>
#include "includes/patricia.h"
#include "includes/patricia_if.h"
#include "includes/benckmark.h"
#include "includes/tst.h"
#include "includes/tst_if.h"
#include "includes/menu.h"

int main() {
 /*   Benchmark benchPatricia;
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
<<<<<<< HEAD
     */
    menu();

    // printf("Tempo de execução patricia:%lf \n",benchmarkGetTime(benchPatricia) );
     //printf("Comparações Patricia:%d \n",benchmarkGetComparations(benchPatricia));
     //printf("Memória Patricia:%d \n",benchmarkGetMemory(benchPatricia));
     //printf("Tempo de execução tst:%lf \n",benchmarkGetTime(benchTst) );
     //printf("Comparações tst:%d \n",benchmarkGetComparations(benchTst));
     //printf("Memória tst:%d \n",benchmarkGetMemory(benchTst));

    return 0;
}
