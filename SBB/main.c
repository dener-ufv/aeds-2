#include <stdio.h>
#include "sbbt.h"

int main() {
    int i;
    int N = 15;
    int MOD = 7;
    int rem = 0;
    Sbbt tree;
    sbbt_init(&tree);

    for(i=1; i<=N; i++)
        sbbt_insert(&tree, i);

    for(i=1; i<=N; i++) {
        sbbt_remove(&tree, rem+1);
        printf("%2d -> %d\n", rem+1, sbbt_get_heigh(tree));
        rem = (rem + MOD) % N;
    }

    return 0;
}
