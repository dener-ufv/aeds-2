/*
    Implementação da SBB modificada
    vários testes feitos, porém não está 100% verificado
*/
#include <stdio.h>
#include "sbbt.h"

int main() {
    int i;
    Sbbt tree;
    sbbt_init(&tree);

    sbbt_insert(&tree, 1);
    sbbt_insert(&tree, 2);
    sbbt_insert(&tree, 3);
    sbbt_insert(&tree, 4);
    sbbt_insert(&tree, 5);
    sbbt_insert(&tree, 6);
    sbbt_insert(&tree, 7);
    sbbt_insert(&tree, 8);
    sbbt_insert(&tree, 9);
    sbbt_insert(&tree, 10);
    sbbt_insert(&tree, 11);
    sbbt_insert(&tree, 12);
    sbbt_insert(&tree, 13);
    sbbt_insert(&tree, 14);
    sbbt_insert(&tree, 15);

    printf("%d\n", sbbt_get_heigh(tree));
    
    int rem = 0;
    for(i=1; i<=15; i++) {
        sbbt_remove(&tree, rem+1);
        printf("%2d -> %d\n", rem+1, sbbt_get_heigh(tree));
        rem = (rem + 11) % 15;
    }

    return 0;
}
