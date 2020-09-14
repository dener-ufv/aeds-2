#include <stdio.h>
#include "sbbt.h"

int main() {

    Sbbt tree;
    sbbt_init(&tree);

    sbbt_insert(&tree, 3);
    sbbt_insert(&tree, 1);
    sbbt_insert(&tree, 2);

    printf("%d\n", sbbt_get_info(tree));
    
    return 0;
}
