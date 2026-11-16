#include "student.h"
extern int id;
void stud_save(ST *hptr)
{
    FILE *fp = fopen("Student_database.txt","w");
    if(fp == NULL)
    {
        printf("File Open Failed...\n");
        return;
    }

    while(hptr)
    {
        fprintf(fp,"%d %s %f\n",hptr->roll,hptr->name,hptr->percentage);
        hptr = hptr->next;
    }
    fclose(fp);
    printf("Records Saved Successfully...\n");
}
void stud_load(ST **hptr)
{
    FILE *fp;
    ST *newnode,*temp;
    int maxroll = 99;
    fp = fopen("Student_database.txt","r");

    if(fp == NULL)
    {
        return;
    }

    while(1)
    {
        newnode = (ST *)malloc(sizeof(ST));

        if(newnode == NULL)
        {
            fclose(fp);
            return;
        }

        if(fscanf(fp,"%d %s %f",&newnode->roll,newnode->name,&newnode->percentage) != 3)
        {
            free(newnode);
            break;
        }

        if(newnode->roll > maxroll)
        {
            maxroll = newnode->roll;
        }

        newnode->next = NULL;

        if(*hptr == NULL)
        {
            *hptr = newnode;
        }
        else
        {
            temp = *hptr;

            while(temp->next)
            {
                temp = temp->next;
            }

            temp->next = newnode;
        }
    }

    fclose(fp);

    id = maxroll + 1;
}
