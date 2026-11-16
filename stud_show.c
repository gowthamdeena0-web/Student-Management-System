#include "student.h"

void stud_show(ST *hptr)
{
    if(hptr == NULL)
    {
        printf("No Records Available...\n");
        return;
    }

    printf("\n");

    printf("=========================================================\n");
    printf("%-10s %-20s %-15s\n",
           "Roll No",
           "Name",
           "Percentage");

    printf("=========================================================\n");

    while(hptr)
    {
        printf("%-10d %-20s %-15.2f\n",
               hptr->roll,
               hptr->name,
               hptr->percentage);

        hptr = hptr->next;
    }

    printf("=========================================================\n");
}
