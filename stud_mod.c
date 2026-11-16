#include "student.h"

void stud_mod(ST *hptr)
{
    char choice;
    int roll;

    if(hptr == NULL)
    {
        printf("No Records Available...\n");
        return;
    }

    printf("\n====================================\n");
    printf("        MODIFY RECORD MENU\n");
    printf("====================================\n");
    printf("R/r : Search By Roll Number\n");
    printf("N/n : Search By Name\n");
    printf("P/p : Search By Percentage\n");
    printf("B/b : Back To Main Menu\n");
    printf("====================================\n");

    printf("Enter Your Choice : ");
    scanf(" %c",&choice);

    if(choice=='R' || choice=='r')
    {
        printf("Enter Roll Number : ");
        scanf("%d",&roll);
    }
    else if(choice=='N' || choice=='n')
    {
        char name[50];
        int found = 0;
        ST *temp = hptr;

        printf("Enter Name : ");
        scanf("%s",name);

        printf("\nMatching Records\n");
        printf("====================================\n");

        while(temp)
        {
            if(strcmp(temp->name,name)==0)
            {
                printf("%d\t%s\t%.2f\n",
                       temp->roll,
                       temp->name,
                       temp->percentage);

                found = 1;
            }

            temp = temp->next;
        }

        if(found == 0)
        {
            printf("No Records Found...\n");
            return;
        }

        printf("\nEnter Roll Number To Modify : ");
        scanf("%d",&roll);
    }
    else if(choice=='P' || choice=='p')
    {
        float per;
        int found = 0;
        ST *temp = hptr;

        printf("Enter Percentage : ");
        scanf("%f",&per);

        printf("\nMatching Records\n");
        printf("====================================\n");

        while(temp)
        {
            if(temp->percentage == per)
            {
                printf("%d\t%s\t%.2f\n",
                       temp->roll,
                       temp->name,
                       temp->percentage);

                found = 1;
            }

            temp = temp->next;
        }

        if(found == 0)
        {
            printf("No Records Found...\n");
            return;
        }

        printf("\nEnter Roll Number To Modify : ");
        scanf("%d",&roll);
    }
    else
    {
        return;
    }

    ST *temp = hptr;

    while(temp)
    {
        if(temp->roll == roll)
        {
            printf("\nRecord Found\n");
            printf("Roll No    : %d\n",temp->roll);
            printf("Name       : %s\n",temp->name);
            printf("Percentage : %.2f\n",temp->percentage);

            printf("\nN/n : Modify Name\n");
            printf("P/p : Modify Percentage\n");

            printf("Enter Your Choice : ");
            scanf(" %c",&choice);

            if(choice=='N' || choice=='n')
            {
                printf("Enter New Name : ");
                scanf("%s",temp->name);

                printf("Name Updated Successfully...\n");
            }
            else if(choice=='P' || choice=='p')
            {
                printf("Enter New Percentage : ");
                scanf("%f",&temp->percentage);

                printf("Percentage Updated Successfully...\n");
            }

            return;
        }

        temp = temp->next;
    }

    printf("Record Not Found...\n");
}
