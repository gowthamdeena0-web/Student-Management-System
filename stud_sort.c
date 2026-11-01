#include "student.h"

void stud_sort(ST *hptr) {
    if (hptr == NULL) {
        printf("No records are available to sort...\n");
        return;
    }

    char choice;
    printf("\n=============================\n");
    printf("        SORT RECORDS MENU\n");
    printf("=============================\n");
    printf("N/n : Sort by Name (Ascending)\n");
    printf("P/p : Sort by Percentage (Descending)\n");
    printf("B/b : Back to Main Menu\n");
    printf("=============================\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &choice);

    ST *i, *j;
    int tempRoll;
    char tempName[50];
    float tempPerc;

    if (choice == 'N' || choice == 'n') {
        // 🔹 Sorting 
        for (i = hptr; i != NULL; i = i->next) {
            for (j = i->next; j != NULL; j = j->next) {
                if (strcmp(i->name, j->name) > 0) {
                    // swapping operation
                    tempRoll = i->roll;
                    i->roll = j->roll;
                    j->roll = tempRoll;

                    strcpy(tempName, i->name);
                    strcpy(i->name, j->name);
                    strcpy(j->name, tempName);

                    tempPerc = i->percentage;
                    i->percentage = j->percentage;
                    j->percentage = tempPerc;
                }
            }
        }
        printf("Records sorted by Name Successfully....!\n");
    }
    else if (choice == 'P' || choice == 'p') {
        //Sorting 
        for (i = hptr; i != NULL; i = i->next) {
            for (j = i->next; j != NULL; j = j->next) {
                if (i->percentage < j->percentage) {  
                    // swapping operation
                    tempRoll = i->roll;
                    i->roll = j->roll;
                    j->roll = tempRoll;

                    strcpy(tempName, i->name);
                    strcpy(i->name, j->name);
                    strcpy(j->name, tempName);

                    tempPerc = i->percentage;
                    i->percentage = j->percentage;
                    j->percentage = tempPerc;
                }
            }
        }
        printf("Records sorted by Percentage Successfully...\n");
    }
    else if (choice == 'B' || choice == 'b') {
        printf("Returning to main menu...\n");
        return;
    }
    else {
        printf("Invalid choice! Please Enter a Valid Choice...\n");
    }
}

