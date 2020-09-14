#include "sbbt.h"

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
static void LL(Slope *parentSlope, Sbbt *root);
static void LR(Slope *parentSlope, Sbbt *root);
static void RL(Slope *parentSlope, Sbbt *root);
static void RR(Slope *parentSlope, Sbbt *root);


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

    /* verify LL, LR, RL, RR horizontal cases */
    if((*root)->leftSlope == horizontal && (*root)->left->leftSlope == horizontal) {
        // LL case
        LL(parentSlope, root);
    }
    if((*root)->leftSlope == horizontal && (*root)->left->rightSlope == horizontal) {
        // LR case
        LR(parentSlope, root);
    }
    if((*root)->rightSlope == horizontal && (*root)->right->leftSlope == horizontal) {
        // RL case
        RL(parentSlope, root);
    }
    if((*root)->rightSlope == horizontal && (*root)->right->rightSlope == horizontal) {
        // RR case
        RR(parentSlope, root);
    }
}

static void LL(Slope *parentSlope, Sbbt *root) {
    Sbbt left = (*root)->left;
    (*root)->left = left->right;
    (*root)->leftSlope = vertical;
    left->right = *root;
    left->leftSlope = vertical;
    left->rightSlope = vertical;
    *root = left;
    *parentSlope = horizontal;
}

static void LR(Slope *parentSlope, Sbbt *root) {
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
    *parentSlope = horizontal;
}

static void RL(Slope *parentSlope, Sbbt *root) {
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
    *parentSlope = horizontal;
}

static void RR(Slope *parentSlope, Sbbt *root) {
    Sbbt right = (*root)->right;
    (*root)->right = right->left;
    (*root)->rightSlope = vertical;
    right->left = *root;
    right->leftSlope = vertical;
    right->rightSlope = vertical;
    *root = right;
    *parentSlope = horizontal;
}



/* public implentations */
void sbbt_init(Sbbt *root) {
    *root = NULL;
}

void sbbt_insert(Sbbt *root, int val) {
    Slope parentSlope;
    insert(&parentSlope, root, val);
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
