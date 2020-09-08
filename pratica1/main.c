#include "student.h"
#include "tree.h"
#include "stdio.h"
#include <stdio.h>
#include <stdlib.h>

int read_student(FILE *stream, Student *s) {
    char name[100];
    int code;
    int grade;
    int group;
    int ok = fscanf(stream, "%s %d %d %d\n", name, &code, &group, &grade);
    if(ok == EOF) return 0;
    student_init(s, code, name, grade, group);
    return 1;
}

void print_student(Student s) {
    printf("%s %d %d %d\n", s.name, s.group, s.code, s.grade);
}

void print_tree_descending_grade(Tree t) {
    if(t == NULL) return;
    print_tree_descending_grade(t->right);
    print_student(t->info);
    print_tree_descending_grade(t->left);
}

void print_number_of_students(Tree t) {
    printf("%d\n", tree_get_size(t));
}

void print_largest_grade(Tree t) {
    printf("%d\n", tree_get_largest(t).grade);
}

void print_smallest_grade(Tree t) {
    printf("%d\n", tree_get_smallest(t).grade);
}

void print_largest_grade_group(Tree t) {
    printf("%d\n", tree_get_largest(t).group);
}

int calculate_aproved_students(Tree t, int average) {
    if(t == NULL) return 0;
    if(t->info.grade >= average) 
        return  1 + 
                tree_get_size(t->right) + 
                calculate_aproved_students(t->left, average);
    return calculate_aproved_students(t->right, average);
}

void print_number_of_aproved_students(Tree t) {
    printf("%d\n", calculate_aproved_students(t, 60));
}

int main() {

    FILE *inp;
    inp = fopen("input.txt", "r");

    Student s;
    Tree t;
    tree_init(&t);
    while(read_student(inp, &s)) {
        tree_insert_student(&t, s);
    }

    print_tree_descending_grade(t);
    printf("\n");
    print_number_of_students(t);
    printf("\n");
    print_smallest_grade(t);
    print_largest_grade(t);
    printf("\n");
    print_largest_grade_group(t);
    printf("\n");
    print_number_of_aproved_students(t);
    printf("\n");


    return 0;
}
