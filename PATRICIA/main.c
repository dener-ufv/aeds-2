#include <stdio.h>
#include "patricia.h"

void print_patricia(Patricia root) {
    if(root == NULL) return;
    if(patricia_is_leaf_node(root)) {
        printf("%d. ", patricia_get_info(root));
        return;
    }
    print_patricia(patricia_get_left_node(root));
    print_patricia(patricia_get_right_node(root));
}


int main() {

    Patricia p;
    patricia_init(&p);

    patricia_insert(&p, 10);
    patricia_insert(&p, 7);
    patricia_insert(&p, 2);
    patricia_insert(&p, 9);
    patricia_insert(&p, 33);
    patricia_insert(&p, 10000);
    patricia_insert(&p, 0);

    print_patricia(p);
    printf("\n");

    return 0;
}
