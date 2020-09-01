#include <stdio.h>

#include "tree.h"

void print_tree_in_order(TreePtr root) {
    if(root == NULL) return;
    print_tree_in_order(tree_get_left_node(root));
    printf("%d ", (int)tree_get_item(root));
    print_tree_in_order(tree_get_right_node(root));
}

void print_tree_pre_order(TreePtr root) {
    if(root == NULL) return;
    printf("%d ", (int)tree_get_item(root));
    print_tree_pre_order(tree_get_left_node(root));
    print_tree_pre_order(tree_get_right_node(root));
}

void print_tree_post_order(TreePtr root) {
    if(root == NULL) return;
    print_tree_post_order(tree_get_left_node(root));
    print_tree_post_order(tree_get_right_node(root));
    printf("%d ", (int)tree_get_item(root));
}

void println() {
    printf("\n");
}

int main() {

    TreePtr root;
    tree_init(&root);
    tree_insert_item(&root, (Item)10);
    tree_insert_item(&root, (Item)11);
    tree_insert_item(&root, (Item)9);
    tree_insert_item(&root, (Item)12);


    print_tree_in_order(root);
    println();

    print_tree_pre_order(root);
    println();

    print_tree_post_order(root);
    println();

    return 0;
}
