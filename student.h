#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Defining our own Structure
typedef struct student {
    int roll;
    char name[50];
    float percentage;
    struct student *next;
} ST;

// Function declarations
void stud_add(ST **);
void stud_del(ST **);
void stud_show(ST *);
void stud_mod(ST *);
void stud_save(ST *);
void stud_sort(ST *);

