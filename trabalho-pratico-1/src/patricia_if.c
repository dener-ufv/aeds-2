#include "includes/patricia_if.h"
#include <stdlib.h>
#include <stdio.h>

void patriciaPrintWords(Patricia root) {
    if(root == NULL) return;
    patriciaPrintWords(patriciaGetLeft(root));
    if(patriciaIsLeaf(root)) {
        printf("%s\n", wordGetString(patriciaGetWord(root)));
    }
    patriciaPrintWords(patriciaGetRight(root));
}
