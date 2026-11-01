#include "student.h"

void stud_save(ST *hptr) {
    if (hptr == NULL) {
        fprintf(stderr,"No records in the file...\n");
        return;
    }

    FILE *fp = fopen("Student_database.txt", "w");
    if (fp == NULL) {
        printf("No file exists....!\n");
        return;
    }

    while (hptr != NULL) {
        fprintf(fp, "%d %s %.2f\n", hptr->roll, hptr->name, hptr->percentage);
        hptr = hptr->next;
    }

    fclose(fp);
    printf("Records saved successfully to student_db.txt\n");
}

