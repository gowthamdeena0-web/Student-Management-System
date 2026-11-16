#include "student.h"

extern int id;

void stud_add(ST **hptr)
{
    char op;
    ST *newnode, *temp;

    do
    {
        newnode = (ST *)malloc(sizeof(ST));

        if(newnode == NULL)
        {
            printf("Memory Allocation Failed...\n");
            return;
        }

        newnode->roll = id++;

        printf("Enter Student Name : ");
        scanf("%s", newnode->name);

        printf("Enter Percentage : ");
        scanf("%f", &newnode->percentage);

        newnode->next = NULL;

        if(*hptr == NULL)
        {
            *hptr = newnode;
        }
        else
        {
            temp = *hptr;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newnode;
        }

        printf("\nRecord Added Successfully...\n");
        printf("Roll Number : %d\n", newnode->roll);

        printf("\nDo You Want To Add Another Record (Y/N) : ");
        scanf(" %c", &op);

    } while(op=='Y' || op=='y');
}
