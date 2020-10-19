#include <stdio.h>
#include "includes/patricia.h"
#include "includes/patricia_if.h"

int main() {
    
    Word w;
    wordInit(&w);

    Patricia tree;
    patriciaInit(&tree);

    int N = 5;
    char* list[] = {"amor", "amarelo", "baleia", "amar", "bala"};

    int i;
    for(i=0; i<N; i++) {
        wordSetString(&w, list[i]);
        patriciaInsert(&tree, w, NULL);
    }

    patriciaPrintWords(tree);

    return 0;
}
