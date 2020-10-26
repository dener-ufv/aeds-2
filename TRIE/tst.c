#include "tst.h"


struct tst_t {
    char c;
    int end;
    Tst left, middle, right;
};

static Tst node_alloc(char c);
static void insert_string(Tst *root, char *str, int len, int pos);

static Tst node_alloc(char c) {
    Tst new = (Tst) malloc(sizeof *new);
    new->c = c;
    new->end = false;
    new->left = NULL;
    new->middle = NULL;
    new->right = NULL;
    return new;
}

static void insert_string(Tst *root, char *str, int len, int pos) {
    if(*root == NULL) {
        *root = node_alloc(str[pos]);
    }
    if(pos == len-1 && (*root)->c == str[pos]) {
        (*root)->end = true;
        return;
    }
    if((*root)->c == str[pos]) {
        insert_string(&(*root)->middle, str, len, pos+1);
    } else if((*root)->c >= str[pos]) {
        insert_string(&(*root)->left, str, len, pos);
    } else {
        insert_string(&(*root)->right, str, len, pos);
    }
}

void tst_init(Tst *root) {
    *root = NULL;
}

void tst_insert_string(Tst *root, char *str, int len) {
    insert_string(root, str, len, 0);
}

char tst_get_char(Tst root) {
    return root->c;
}

int tst_is_end_of_string(Tst root) {
    return root->end;
}

Tst tst_get_left_node(Tst root) {
    return root->left;
}

Tst tst_get_right_node(Tst root) {
    return root->right;
}

Tst tst_get_middle_node(Tst root) {
    return root->middle;
}
