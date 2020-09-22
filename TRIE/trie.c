#include "trie.h"

#define MAX_SON 26

struct trie_t {
    int end;
    Trie son[MAX_SON];
};

static Trie node_alloc();
static void insert_string(Trie *root, char *str, int len, int pos);


static Trie node_alloc() {
    int i;
    Trie new = (Trie) malloc(sizeof *new);
    new->end = false;
    for(i=0; i<MAX_SON; i++) {
        new->son[i] = NULL;
    }
    return new;
}

static void insert_string(Trie *root, char *str, int len, int pos) {
    if(*root == NULL) {
       *root = node_alloc(); 
    }
    if(pos == len-1) {
        (*root)->end = true;
        return;
    }
    insert_string(&(*root)->son[str[pos+1] - 'a'], str, len, pos+1);
}

void trie_init(Trie *root) {
    *root = NULL;
}

void trie_insert_string(Trie *root, char *str, int len) {
    insert_string(root, str, len, -1);
}

int trie_is_end_of_string(Trie root) {
    return root->end;
}

Trie trie_get_ith_son(Trie root, int i) {
    return root->son[i];
}

int trie_get_max_sons(void) {
    return MAX_SON;
}
