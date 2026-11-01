#include "student.h"

int main() {
    ST *hptr = NULL;   // head pointer initially pointing to NULL
    char choice;
    //Menu options
    do {
        printf("\n====================================\n");
        printf("       STUDENT MANAGEMENT SYSTEM\n");
        printf("====================================\n");
        printf("|  Choice  |       Operation        |\n");
        printf("====================================\n");
        printf("|   A/a    |  Add New Record        |\n");
        printf("|   D/d    |  Delete a Record       |\n");
        printf("|   S/s    |  Show Records          |\n");
        printf("|   M/m    |  Modify a Record       |\n");
        printf("|   V/v    |  Save Records          |\n");
        printf("|   T/t    |  Sort Records          |\n");
        printf("|   E/e    |  Exit                  |\n");
        printf("====================================\n");
        printf("Enter Your Choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'A': case 'a':
                stud_add(&hptr);
                break;

            case 'D': case 'd':
                stud_del(&hptr);
                break;

            case 'S': case 's':
                stud_show(hptr);
                break;

            case 'M': case 'm':
                stud_mod(hptr);
                break;

            case 'V': case 'v':
                stud_save(hptr);
                break;

            case 'T': case 't':
                stud_sort(hptr);
                break;

            case 'E': case 'e':
                printf("\n=============================\n");
                printf("          EXIT MENU\n");
                printf("=============================\n");
                printf("S/s : Save and Exit\n");
                printf("E/e : Exit Without Saving\n");
                printf("B/b : Back to Main Menu\n");
                printf("=============================\n");
                printf("Enter Your Choice: ");
                scanf(" %c", &choice);

                if (choice == 'S' || choice == 's') {
                    stud_save(hptr);
                    printf("Records saved. Exiting program...\n");
                    return 0;
                } else if (choice == 'E' || choice == 'e') {
                    printf("Exiting without saving...\n");
                    return 0;
                } else if (choice == 'B' || choice == 'b') {
                    printf("Returning to main menu...\n");
                    break;
                } else {
                    printf("Invalid choice! Returning to main menu...\n");
                }
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (1);

    return 0;
}

