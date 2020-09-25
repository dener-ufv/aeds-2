#include "patricia.h"

#define LEAF -1

struct patricia_t {
    int index;
    int *info;
    Patricia left, right;  
};

static Patricia node_alloc(int *info, int index, Patricia left, Patricia right);

static Patricia node_alloc(int *info, int index, Patricia left, Patricia right) {
    Patricia new = (Patricia) malloc(sizeof *new);
    new->index = index;
    new->left = left;
    new->right = right;
    new->info = info;
    return new;
}

void patricia_init(Patricia *root) {
    *root = NULL;
}

void patricia_insert(Patricia *root, int value) {
    int i, size, info;
    Patricia l, r, *it, auxRoot;
    if(*root == NULL) {
        *root = node_alloc(new_int(value), LEAF, NULL, NULL);
        return;
    }

    it = root;
    while((*it)->index != LEAF) {
        if(value>>(*it)->index&1) it = &(*it)->right;
        else it = &(*it)->left;
    }
    auxRoot = *it;

    size = 8*sizeof(int);
    for(i=size-1; i>=0 && (value>>i&1) == (*auxRoot->info>>i&1); i--); 
    if(i < 0) return;

    it = root;
    while((*it)->index != LEAF && i >= (*it)->index) {
        if(value>>(*it)->index&1) it = &(*it)->right;
        else it = &(*it)->left;
    }

    if(value>>i&1) {
        l = *it;
        r = node_alloc(new_int(value), -1, NULL, NULL);
    } else {
        l = node_alloc(new_int(value), -1, NULL, NULL);
        r = *it;
    }

    *it = node_alloc(NULL, i, l, r);
}

Patricia patricia_get_left_node(Patricia root) {
    return root->left;
}

Patricia patricia_get_right_node(Patricia root) {
    return root->right;
}

int      patricia_get_info(Patricia root) {
    return *root->info;
}

int      patricia_is_leaf_node(Patricia root) {
    return root->index == -1;
}
