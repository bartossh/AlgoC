#include "grade_school.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *elem1, const void *elem2)
{
    student_t f = *((student_t *)elem1);
    student_t s = *((student_t *)elem2);
    if (f.grade < s.grade)
    {
        return -1;
    }

    if (f.grade > s.grade)
    {
        return 1;
    }
    int cmp = strcmp(f.name, s.name);
    if (cmp < 0)
    {
        return -1;
    }
    else if (cmp > 0)
    {
        return 1;
    }
    return 0;
}

void init_roster(roster_t *actual)
{
    actual->count = 0;
    for (size_t i = 0; i < MAX_STUDENTS; i++)
    {
        actual->students[i].grade = 0;
        actual->students[i].name[0] = '\0';
    }
}

int add_student(roster_t *roster, char name[], uint8_t grade)
{
    if (roster == NULL)
    {
        return 0;
    }
    if (roster->count >= MAX_STUDENTS)
    {
        return 0;
    }

    for (size_t i = 0; i < roster->count; i++)
    {
        int cmp = strcmp(roster->students[i].name, name);
        if (cmp == 0)
        {
            return 0;
        }
    }

    student_t student;
    student.grade = grade;
    for (size_t i = 0; i < MAX_NAME_LENGTH; i++)
    {
        student.name[i] = name[i];
    }
    roster->students[roster->count] = student;
    roster->count++;

    qsort(roster->students, roster->count, sizeof(student_t), compare);

    return 1;
}

roster_t get_grade(roster_t *roster, int desired_grade)
{
    roster_t actual = {0};
    if (roster == NULL)
    {
        return actual;
    }

    for (size_t i = 0; i < roster->count; i++)
    {
        if (roster->students[i].grade == desired_grade)
        {
            add_student(&actual, roster->students[i].name, desired_grade);
        }
    }

    return actual;
}
