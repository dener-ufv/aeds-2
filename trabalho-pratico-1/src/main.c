#include <stdio.h>
#include "includes/patricia.h"

int main() {
    
    Patricia p;
    Word w;

    wordInit(&w);
    patriciaInit(&p);

    wordSetString(&w, "abc");
    patriciaInsert(&p, w, NULL);
    
    
    patriciaDelete(&p);
    wordDelete(&w);

    return 0;
}
