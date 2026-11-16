#include "student.h"

void stud_del(ST **hptr)
{
    if(*hptr == NULL)
    {
        printf("No Records Available...\n");
        return;
    }

    int roll;
    char choice;

    printf("\n====================================\n");
    printf("        DELETE RECORD MENU\n");
    printf("====================================\n");
    printf("R/r : Delete Using Roll Number\n");
    printf("N/n : Delete Using Name\n");
    printf("B/b : Back To Main Menu\n");
    printf("====================================\n");

    printf("Enter Your Choice : ");
    scanf(" %c",&choice);

    if(choice=='R' || choice=='r')
    {
        ST *temp=*hptr,*prev=NULL;

        printf("Enter Roll Number To Delete : ");
        scanf("%d",&roll);

        while(temp)
        {
            if(temp->roll==roll)
            {
                printf("\nRecord Found\n");
                printf("Roll No    : %d\n",temp->roll);
                printf("Name       : %s\n",temp->name);
                printf("Percentage : %.2f\n",temp->percentage);

                printf("\nDelete This Record(Y/N) : ");
                scanf(" %c",&choice);

                if(choice=='Y' || choice=='y')
                {
                    if(prev==NULL)
                        *hptr=temp->next;
                    else
                        prev->next=temp->next;

                    free(temp);

                    printf("Record Deleted Successfully...\n");
                }

                return;
            }

            prev=temp;
            temp=temp->next;
        }

        printf("Record Not Found...\n");
    }

    else if(choice=='N' || choice=='n')
    {
        char name[50];
        int found=0;

        printf("Enter Name To Delete : ");
        scanf("%s",name);

        ST *temp=*hptr;

        printf("\nMatching Records\n");
        printf("====================================================\n");
        printf("Roll No\t\tName\t\tPercentage\n");
        printf("====================================================\n");

        while(temp)
        {
            if(strcmp(temp->name,name)==0)
            {
                printf("%d\t\t%s\t\t%.2f\n",
                       temp->roll,
                       temp->name,
                       temp->percentage);

                found=1;
            }

            temp=temp->next;
        }

        if(found==0)
        {
            printf("No Matching Records Found...\n");
            return;
        }

        printf("\nEnter Roll Number To Delete : ");
        scanf("%d",&roll);

        temp=*hptr;
        ST *prev=NULL;

        while(temp)
        {
            if(temp->roll==roll)
            {
                printf("Delete This Record(Y/N) : ");
                scanf(" %c",&choice);

                if(choice=='Y' || choice=='y')
                {
                    if(prev==NULL)
                        *hptr=temp->next;
                    else
                        prev->next=temp->next;

                    free(temp);

                    printf("Record Deleted Successfully...\n");
                }

                return;
            }

            prev=temp;
            temp=temp->next;
        }

        printf("Roll Number Not Found...\n");
    }

    else if(choice=='B' || choice=='b')
    {
        return;
    }

    else
    {
        printf("Invalid Choice...\n");
    }
}
