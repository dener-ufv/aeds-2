#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "string.h"

typedef struct {
    int grade;
    char name[64];
    int code;
    int group;
} Student;

void student_init(Student *s, int code, char name[], int grade, int group);
int student_get_code(Student s);
int student_get_grade(Student s);
int student_get_group(Student s);
void student_get_name(Student s, char name[]);
int student_compare(Student a, Student b);

#endif
