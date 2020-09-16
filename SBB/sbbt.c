#include "sbbt.h"

//#include <stdio.h>

#define max(a,b) a>b?a:b

typedef enum {
    vertical, horizontal
} Slope;

struct sbbt_t {
    int info;
    Sbbt left, right;
    Slope leftSlope, rightSlope;
};

/* private definitions */
static Sbbt node_alloc(int info, Sbbt left, Sbbt right, Slope leftSlope, Slope rightSlope);
static void insert(Slope *parentSlope, Sbbt *root, int val);
static int  remove(Slope *parentSlope, Sbbt *root, int val);
static int  remove_larger(Slope *parentSlope, Sbbt *root, int *info);
static void LL(Sbbt *root);
static void LR(Sbbt *root);
static void RL(Sbbt *root);
static void RR(Sbbt *root);
static void UP(Sbbt *root);
static int  down_left(Slope *parentSlope, Sbbt *root);
static int  down_right(Slope *parentSlope, Sbbt *root);
static int  apply_transforms(Sbbt *root);


/* private implementations */
static Sbbt node_alloc(int info, Sbbt left, Sbbt right, Slope leftSlope, Slope rightSlope) {
    Sbbt new = (Sbbt) malloc(sizeof *new);
    new->info = info;
    new->left = left;
    new->right = right;
    new->leftSlope = leftSlope;
    new->rightSlope = rightSlope;
    return new;
}

// 
static void insert(Slope *parentSlope, Sbbt *root, int val) {
    /* insert case */
    if(*root == NULL) {
        *root = node_alloc(val, NULL, NULL, vertical, vertical);
        *parentSlope = horizontal;
        return;
    }

    /* recurse on subtrees */
    if(val <= (*root)->info) 
        insert(&(*root)->leftSlope, &(*root)->left, val);
    else
        insert(&(*root)->rightSlope, &(*root)->right, val);

    if( apply_transforms(root) ) {
        *parentSlope = horizontal;
    }
}

static int remove(Slope *parentSlope, Sbbt *root, int val) {
    Sbbt auxRoot;
    Slope auxSlope;

    if(*root == NULL) {
        return 1;
    }

    if(val < (*root)->info) {
        if( remove(&(*root)->leftSlope, &(*root)->left, val) ) return 1;
        return down_left(parentSlope, root);
    }

    if(val > (*root)->info) {
        if( remove(&(*root)->rightSlope, &(*root)->right, val) ) return 1;
        return down_right(parentSlope, root);
    }

    if((*root)->right == NULL) {
        auxRoot = (*root)->left;
        if(auxRoot) {
            (*root)->info = auxRoot->info;
            (*root)->leftSlope = vertical;
            (*root)->left = NULL;
            free(auxRoot);
            return 1;
        }
    }

    if((*root)->left == NULL) {
        auxRoot = (*root)->right;
        if(auxRoot) {
            (*root)->info = auxRoot->info;
            (*root)->rightSlope = vertical;
            (*root)->right = NULL;
            free(auxRoot);
            return 1;
        }
    }

    if((*root)->left == NULL && (*root)->right == NULL) {
        auxRoot = *root;
        auxSlope = *parentSlope;
        *root = NULL;
        *parentSlope = vertical;
        free(auxRoot);
        if(auxSlope == horizontal) return 1;
        return 0;
    }

    if( remove_larger(&(*root)->leftSlope, &(*root)->left, &(*root)->info) ) return 1;
    return down_left(parentSlope, root);
}

static int  remove_larger(Slope *parentSlope, Sbbt *root, int *info) {
    Sbbt auxRoot;
    Slope auxSlope;
    
    if((*root)->right) {
        if( remove_larger(&(*root)->rightSlope, &(*root)->right, info) ) return 1;
        return down_right(parentSlope, root);
    }

    auxRoot = (*root)->left;
    if(auxRoot) {
        *info = (*root)->info;
        (*root)->info = auxRoot->info;
        (*root)->leftSlope = vertical;
        (*root)->left = NULL;
        free(auxRoot);
        return 1;
    }

    auxSlope = *parentSlope;
    *info = (*root)->info;
    auxRoot = *root;
    *root = NULL;
    *parentSlope = vertical;
    free(auxRoot);
    if(auxSlope == horizontal) return 1;
    return 0;
}

static void LL(Sbbt *root) {
    Sbbt left = (*root)->left;
    (*root)->left = left->right;
    (*root)->leftSlope = vertical;
    left->right = *root;
    left->leftSlope = vertical;
    left->rightSlope = vertical;
    *root = left;
}

static void LR(Sbbt *root) {
    Sbbt left = (*root)->left;
    Sbbt newRoot = left->right;
    (*root)->left = newRoot->right;
    (*root)->leftSlope = vertical;
    left->right = newRoot->left;
    left->rightSlope = vertical;
    newRoot->left = left;
    newRoot->right = *root;
    newRoot->leftSlope = vertical;
    newRoot->rightSlope = vertical;
    *root = newRoot;
}

static void RL(Sbbt *root) {
    Sbbt right = (*root)->right;
    Sbbt newRoot = right->left;
    (*root)->right = newRoot->left;
    (*root)->rightSlope = vertical;
    right->left = newRoot->right;
    right->leftSlope = vertical;
    newRoot->left = *root;
    newRoot->leftSlope = vertical;
    newRoot->right = right;
    newRoot->rightSlope = vertical;
    *root = newRoot;
}

static void RR(Sbbt *root) {
    Sbbt right = (*root)->right;
    (*root)->right = right->left;
    (*root)->rightSlope = vertical;
    right->left = *root;
    right->leftSlope = vertical;
    right->rightSlope = vertical;
    *root = right;
}

static void UP(Sbbt *root) {
    (*root)->leftSlope = vertical;
    (*root)->rightSlope = vertical;
}

static int down_left(Slope *parentSlope, Sbbt *root) {
    Slope auxSlope;
    Sbbt auxRoot;
    if((*root)->rightSlope == vertical) {
        auxSlope = *parentSlope;
        (*root)->rightSlope = horizontal;
        *parentSlope = vertical;
        if( apply_transforms(root) ) {
            *parentSlope = auxSlope;
            return 1;
        }
        if(auxSlope == horizontal) return 1;
    } else {
        auxRoot = (*root)->right;
        (*root)->right = auxRoot->left;
        auxRoot->left = *root;
        if( apply_transforms(root) ) {
            auxRoot->rightSlope = horizontal;
        }
        *root = auxRoot;
        return 1;
    }
    return 0;
}

static int down_right(Slope *parentSlope, Sbbt *root) {
    Slope auxSlope;
    Sbbt auxRoot;
    if((*root)->leftSlope == vertical) {
        auxSlope = *parentSlope;
        (*root)->leftSlope = horizontal;
        *parentSlope = vertical;
        if( apply_transforms(root) ) {
            *parentSlope = auxSlope;
            return 1;
        }
        if(auxSlope == horizontal) return 1;
    } else {
        auxRoot = (*root)->left;
        (*root)->left = auxRoot->right;
        auxRoot->right = *root;
        if( apply_transforms(root) ) {
            auxRoot->rightSlope = horizontal;
        }
        *root = auxRoot;
        return 1;
    }
    return 0;
}

static int  apply_transforms(Sbbt *root) {
    /* verify LL, LR, RL, RR, UP horizontal cases */
    if((*root)->leftSlope == horizontal && (*root)->left->leftSlope == horizontal) {
        // LL case
        LL(root);
        return 1;
    }
    if((*root)->leftSlope == horizontal && (*root)->left->rightSlope == horizontal) {
        // LR case
        LR(root);
        return 1;
    }
    if((*root)->rightSlope == horizontal && (*root)->right->leftSlope == horizontal) {
        // RL case
        RL(root);
        return 1;
    }
    if((*root)->rightSlope == horizontal && (*root)->right->rightSlope == horizontal) {
        // RR case
        RR(root);
        return 1;
    }
    if((*root)->leftSlope == horizontal && (*root)->rightSlope == horizontal) {
        // UP case
        UP(root);
        return 1;
    }
    return 0;
}



/* public implentations */
void sbbt_init(Sbbt *root) {
    *root = NULL;
}

void sbbt_insert(Sbbt *root, int val) {
    Slope parentSlope;
    insert(&parentSlope, root, val);
}

int  sbbt_find(Sbbt *root, int val) {
    Sbbt r = *root;
    while(r != NULL) {
        if(r->info == val) return 1;
        if(val < r->info) r = r->left;
        else r = r->right;
    }
    return 0;
}

void sbbt_remove(Sbbt *root, int val) {
    Slope parentSlope = horizontal;
    remove(&parentSlope, root, val);
}



/* public getters */
Sbbt sbbt_get_left_node(Sbbt root) {
    return root->left;
}

Sbbt sbbt_get_right_node(Sbbt root) {
    return root->right;
}

int sbbt_get_info(Sbbt root) {
    return root->info;
}

int  sbbt_get_heigh(Sbbt root) {
    if(root == NULL) return -1;
    int l = (root->leftSlope == vertical) + sbbt_get_heigh(root->left);
    int r = (root->rightSlope == vertical) + sbbt_get_heigh(root->right);
    return max(l, r);
}
