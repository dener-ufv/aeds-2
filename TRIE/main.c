#include <stdio.h>
#include "trie.h"
#include "tst.h"

void print_strings_trie(Trie root, char *str, int pos) {
    if(root == NULL) return;
    if(trie_is_end_of_string(root)) {
        str[pos] = '\0';
        printf("%s\n", str);
    }
    int max = trie_get_max_sons();
    int i;
    Trie auxRoot;
    for(i=0; i<max; i++) {
        auxRoot = trie_get_ith_son(root, i);
        str[pos] = 'a' + i;
        print_strings_trie(auxRoot, str, pos+1);
    }
}

void print_strings_tst(Tst root, char *str, int pos) {
    if(root == NULL) return;
    str[pos] = tst_get_char(root);
    if(tst_is_end_of_string(root)) {
        str[pos+1] = '\0';
        printf("%s\n", str);
    }
    print_strings_tst(tst_get_middle_node(root), str, pos+1);
    print_strings_tst(tst_get_left_node(root), str, pos);
    print_strings_tst(tst_get_right_node(root), str, pos);
}

int main() {
    char str[100];
    Trie t;
    trie_init(&t);

    // trie_insert_string(&t, "dependencia", 11);
    // trie_insert_string(&t, "despacho", 8);
    // trie_insert_string(&t, "deserto", 7);

    print_strings_trie(t, str, 0);


    Tst r;
    tst_init(&r);
    tst_insert_string(&r, "dependencia", 11);
    tst_insert_string(&r, "despacho", 8);
    tst_insert_string(&r, "deserto", 7);

    print_strings_tst(r, str, 0);

    return 0;
}
