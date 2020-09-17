#include "sbbt.h"

#include <stdio.h>

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
static int  remove_val(Sbbt *root, int val);
static int  remove_larger(Sbbt *root, int *info);
static void LL(Sbbt *root);
static void LR(Sbbt *root);
static void RL(Sbbt *root);
static void RR(Sbbt *root);
static int  small_left(Sbbt *root);
static int  small_right(Sbbt *root);
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

static int remove_val(Sbbt *root, int val) {
    int status = 0;
    Sbbt auxRoot;
    if(*root == NULL) return 1;
    if( val < (*root)->info ) {
        status = remove_val(&(*root)->left, val);
        if(!status) status = small_left(root);
        return status;
    }

    if( val > (*root)->info) {
        status = remove_val(&(*root)->right, val);
        if(!status) status = small_right(root);
        return status;
    }

    if((*root)->right == NULL) {
        auxRoot = *root;
        *root = (*root)->left;
        free(auxRoot);
        if(*root) status = 1;
        return status;
    }

    if((*root)->left == NULL) {
        auxRoot = *root;
        *root = (*root)->right;
        free(auxRoot);
        if(*root) status = 1;
        return status;
    }

    status = remove_larger(&(*root)->left, &(*root)->info);
    if(!status) status = small_left(root);
    return status;
}

static int  remove_larger(Sbbt *root, int *info) {
    int status = 0;
    Sbbt auxRoot;
    if((*root)->right) {
        status = remove_larger(&(*root)->right, info);
        if(!status) status = small_right(root);
        return status;
    }

    auxRoot = *root;
    *root = (*root)->left;
    *info = auxRoot->info;
    free(auxRoot);
    if(*root) status = 1;
    return status;
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

static int small_left(Sbbt *root) {
    Sbbt auxRoot;
    if((*root)->leftSlope == horizontal) {
        (*root)->leftSlope = vertical;
        return 1;
    }
    if((*root)->rightSlope == horizontal) {
        auxRoot = *root;
        *root = (*root)->right;
        auxRoot->right = (*root)->left;
        if( apply_transforms(&auxRoot) ) {
            (*root)->leftSlope = horizontal;
        }
        (*root)->left = auxRoot;
        return 1;
    }
    (*root)->rightSlope = horizontal;
    if( apply_transforms(root) ) return 1;

    return 0;
}

static int small_right(Sbbt *root) {
    Sbbt auxRoot;
    if((*root)->rightSlope == horizontal) {
        (*root)->rightSlope = vertical;
        return 1;
    }
    if((*root)->leftSlope == horizontal) {
        auxRoot = *root;
        *root = (*root)->left;
        auxRoot->left = (*root)->right;
        if( apply_transforms(&auxRoot) ) {
            (*root)->rightSlope = horizontal;
        }
        (*root)->right = auxRoot;
        return 1;
    }
    (*root)->leftSlope = horizontal;
    if( apply_transforms(root) ) return 1;
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
    remove_val(root, val);
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
