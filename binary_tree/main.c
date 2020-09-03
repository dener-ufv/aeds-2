#include "tree.h"
#include "main_view.h"

int main() {

    TreePtr root;
    tree_init(&root);
    tree_insert_item(&root, (Item)10);
    tree_insert_item(&root, (Item)11);
    tree_insert_item(&root, (Item)9);
    tree_insert_item(&root, (Item)12);
    tree_insert_item(&root, (Item)7);

    print_tree_dfs(root);
    println();

    print_tree_bfs(root);
    println();

    return 0;
}
