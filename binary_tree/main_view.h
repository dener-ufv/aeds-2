#ifndef __MAIN_VIEW_H__
#define __MAIN_VIEW_H__

#include "tree.h"
#include "list.h"
#include <stdio.h>

void print_tree_dfs(TreePtr root);
void print_tree_bfs(TreePtr root);
void print_tree_in_order(TreePtr root);
void print_tree_pre_order(TreePtr root);
void print_tree_post_order(TreePtr root);
void println();

#endif
