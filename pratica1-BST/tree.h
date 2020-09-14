#ifndef __TREE_H__
#define __TREE_H__

#include "student.h"
#include <stdlib.h>
typedef struct tree_t * Tree;

struct tree_t {
    Student info;
    Tree left, right;
};

void tree_init(Tree *tree);
void tree_insert_student(Tree *tree, Student s);
int  tree_get_size(Tree tree);
Student  tree_get_largest(Tree tree);
Student  tree_get_smallest(Tree tree);

#endif
