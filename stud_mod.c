#include "student.h"

void stud_mod(ST *hptr) {
    if (hptr == NULL) {
        printf("No records to modify...\n");
        return;
    }

    int roll;
    char choice;

    printf("Enter Roll Number to modify: ");
    scanf("%d", &roll);

    ST *temp = hptr;
    while (temp != NULL && temp->roll != roll) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Record not found!\n");
        return;
    }

    printf("Record Found: Roll=%d, Name=%s, Percentage=%.2f\n",
           temp->roll, temp->name, temp->percentage);

    printf("\n=============================\n");
    printf("       MODIFY RECORD MENU\n");
    printf("=============================\n");
    printf("N/n : Modify Name\n");
    printf("P/p : Modify Percentage\n");
    printf("B/b : Back to Main Menu\n");
    printf("=============================\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &choice);

    if (choice == 'N' || choice == 'n') {
        printf("Enter New Name: ");
        scanf("%s", temp->name);
        printf("Name updated successfully!\n");
    }
    else if (choice == 'P' || choice == 'p') {
        printf("Enter New Percentage: ");
        scanf("%f", &temp->percentage);
        printf("Percentage updated successfully!\n");
    }
    else if (choice == 'B' || choice == 'b') {
        printf("Returning to main menu...\n");
        return;
    }
    else {
        printf("Invalid choice!\n");
    }
}

