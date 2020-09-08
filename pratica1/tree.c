#include "tree.h"

static Tree tree_node_alloc(Student s, Tree left, Tree right) {
    Tree new = (Tree) malloc(sizeof *new);
    new->info = s;
    new->left = left;
    new->right = right;
}

void tree_init(Tree *tree) {
    *tree = NULL;
}

void tree_insert_student(Tree *tree, Student s) {
    Tree *root = tree;
    while(*root != NULL) {
        if(student_compare(s, (*root)->info) <= 0) {
            root = &(*root)->left;
        } else {
            root = &(*root)->right;
        }
    }
    *root = tree_node_alloc(s, NULL, NULL);
}

int  tree_get_size(Tree tree) {
    if(tree == NULL) return 0;
    return 1 + tree_get_size(tree->left) + tree_get_size(tree->right);
}

Student tree_get_largest(Tree tree) {
    Student serr;
    student_init(&serr, -1, "", -1, -1);
    if(tree == NULL) return serr;
    while(tree->right != NULL) tree = tree->right;
    return tree->info;
}

Student tree_get_smallest(Tree tree) {
    Student serr;
    student_init(&serr, -1, "", -1, -1);
    if(tree == NULL) return serr;
    while(tree->left != NULL) tree = tree->left;
    return tree->info;
}
