#include "includes/patricia_if.h"
#include <stdlib.h>
#include "includes/word_if.h"
#include <stdio.h>

void patriciaPrintWords(Patricia root) {
    if(root == NULL) return;
    patriciaPrintWords(patriciaGetLeft(root));
    if(patriciaIsLeaf(root)) {
        wordPrint(patriciaGetWord(root));
        printf("\n");
    }
    patriciaPrintWords(patriciaGetRight(root));
}
