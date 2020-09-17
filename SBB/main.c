#include <stdio.h>
#include "sbbt.h"

int main() {
    int i;
    int N = 15;
    int MOD = 7;
    int rem = 11;
    Sbbt tree;
    sbbt_init(&tree);

    for(i=1; i<=N; i++)
        sbbt_insert(&tree, i);

    sbbt_remove(&tree, rem);
    printf("%2d -> %d\n", rem, sbbt_get_heigh(tree));

    return 0;
}
