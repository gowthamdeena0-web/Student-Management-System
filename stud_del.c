#include "student.h"

void stud_del(ST **hptr) {
    if (*hptr == NULL) {
        printf("No records to delete...\n");
        return;
    }

    int roll;
    char choice;

    printf("\n=============================\n");
    printf("       DELETE RECORD MENU\n");
    printf("=============================\n");
    printf("R/r : Delete using Roll Number\n");
    printf("N/n : Delete using Name\n");
    printf("B/b : Back to Main Menu\n");
    printf("=============================\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &choice);

    if (choice == 'R' || choice == 'r') {
        printf("Enter Roll Number to delete: ");
        scanf("%d", &roll);

        ST *temp = *hptr, *prev = NULL;
        while (temp != NULL && temp->roll != roll) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            printf("Record not found!\n");
            return;
        }

        // confirmation
        printf("Record Found: Roll=%d, Name=%s, Percentage=%.2f\n",
               temp->roll, temp->name, temp->percentage);
        printf("Do you really want to delete? (Y/N): ");
        scanf(" %c", &choice);

        if (choice == 'Y' || choice == 'y') {
            if (prev == NULL) {
                *hptr = temp->next; // deleting head
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Record deleted successfully!\n");
        } else {
            printf("Deletion cancelled.\n");
        }
    }
    else if (choice == 'N' || choice == 'n') {
        char name[50];
        printf("Enter Name to delete: ");
        scanf("%s", name);

        ST *temp = *hptr, *prev = NULL;
        int found = 0;

        while (temp != NULL) {
            if (strcmp(temp->name, name) == 0) {
                found = 1;
                printf("Record Found: Roll=%d, Name=%s, Percentage=%.2f\n",
                       temp->roll, temp->name, temp->percentage);
                printf("Do you really want to delete? (Y/N): ");
                scanf(" %c", &choice);

                if (choice == 'Y' || choice == 'y') {
                    if (prev == NULL) {
                        *hptr = temp->next;
                    } else {
                        prev->next = temp->next;
                    }
                    free(temp);
                    printf("Record deleted successfully!\n");
                    return;
                } else {
                    printf("Deletion cancelled.\n");
                    return;
                }
            }
            prev = temp;
            temp = temp->next;
        }

        if (!found) {
            printf("No record found with name %s\n", name);
        }
    }
    else if (choice == 'B' || choice == 'b') {
        printf("Returning to main menu...\n");
        return;
    }
    else {
        printf("Invalid choice!\n");
    }
}

