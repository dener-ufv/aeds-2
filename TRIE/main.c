#include <stdio.h>
#include "trie.h"

void print_strings(Trie root, char *str, int pos) {
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
        print_strings(auxRoot, str, pos+1);
    }
}

int main() {

    Trie t;
    trie_init(&t);

    trie_insert_string(&t, "dependencia", 11);
    trie_insert_string(&t, "despacho", 8);
    trie_insert_string(&t, "deserto", 7);

    char str[100];
    print_strings(t, str, 0);

    return 0;
}
