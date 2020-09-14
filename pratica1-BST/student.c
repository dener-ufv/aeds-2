#include "student.h"

void student_init(Student *s, int code, char name[], int grade, int group) {
    s->code = code;
    strcpy(s->name, name);
    s->grade = grade;
    s->group = group;
}

int student_get_code(Student s) {
    return s.code;
}

int student_get_grade(Student s) {
    return s.grade;
}

int student_get_group(Student s) {
    return s.group;
}

void student_get_name(Student s, char name[]) {
    strcpy(name, s.name);
}

int student_compare(Student a, Student b) {
    return a.grade - b.grade;
}
