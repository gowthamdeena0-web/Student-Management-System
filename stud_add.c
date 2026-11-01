#include "student.h"

void stud_add(ST **hptr) {
    static int id = 100;
    char op;
    ST *newnode, *temp;

    do {
        newnode = (ST*)malloc(sizeof(ST));//Memory allocation for newnode using dma concept
        if (newnode == NULL) {//indication for memory is created successfully or not
            printf("Memory allocation failed!\n");
            return;
        }

        // roll number logic
        if (*hptr == NULL) {
            newnode->roll = id;
            *hptr = newnode;
        } else {
            temp = *hptr;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            newnode->roll = temp->roll + 1;
            temp->next = newnode;
        }

        // get student details
        printf("Enter Student Name: ");
        scanf("%s", newnode->name);

        printf("Enter Percentage: ");
        scanf("%f", &newnode->percentage);

        newnode->next = NULL;

        printf("Record Added Successfully! (Roll No: %d)\n", newnode->roll);

        // confirmation
        printf("Do you want to add another record? (Y/N): ");
        scanf(" %c", &op);

    } while (op == 'y' || op == 'Y');
}



