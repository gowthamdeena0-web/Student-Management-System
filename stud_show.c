#include "student.h"

void stud_show(ST *hptr) {
    if (hptr == NULL) {
        printf("No records in the list...\n");
        return;
    }

    printf("\n====================================\n");
    printf("        STUDENT RECORDS LIST\n");
    printf("====================================\n");
    printf("| Roll No |     Name     | Percentage |\n");
    printf("--------------------------------------\n");

    while (hptr != NULL) {
        printf("| %-7d | %-10s | %-9.2f |\n",
               hptr->roll, hptr->name, hptr->percentage);
        hptr = hptr->next;
    }

    printf("--------------------------------------\n");
}

