#include "main_view.h"
 
void print_tree_dfs(TreePtr root) {
    if(root == NULL) return;
    List stack;
    TreePtr front, right, left;
    list_init(&stack);
    list_push_front(&stack, root);
    while(list_get_size(stack)) {
        front = list_get_front(stack);
        list_pop_front(&stack);
        printf("%d ", tree_get_item(front));
        right = tree_get_right_node(front);
        left = tree_get_left_node(front);
        if(right) list_push_front(&stack, right);
        if(left) list_push_front(&stack, left);
    }
}

void print_tree_bfs(TreePtr root) {
    if(root == NULL) return;
    List queue;
    TreePtr front, right, left;
    list_init(&queue);
    list_push_back(&queue, root);
    while(list_get_size(queue)) {
        front = list_get_front(queue);
        list_pop_front(&queue);
        printf("%d ", tree_get_item(front));
        right = tree_get_right_node(front);
        left = tree_get_left_node(front);
        if(left) list_push_back(&queue, left);
        if(right) list_push_back(&queue, right);
    }
}

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
