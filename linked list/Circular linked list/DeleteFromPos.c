#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *tail;

void create()
{
    int choice=1;
    tail=0;
    struct node *newnode;
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter data:");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(tail==0)
        {
            tail=newnode;
            tail->next=newnode;
        }
        else
        {
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;
        }
        printf("continue?(0/1):");
        scanf("%d",&choice);
    }
}

void display()
{
    struct node *temp;
    temp=tail->next;
    while(temp->next!=tail->next)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
}

void delFromPos()
{
    int pos,i=1;
    struct node *current,*nextnode;
    current=tail->next;
    printf("\nenter position where you want to delete a node:");
    scanf("%d",&pos);
    while(i<pos-1)
    {
        current=current->next;
        i++;
    }
    nextnode=current->next;
    current->next=nextnode->next;
    free(nextnode);
}

void main()
{
    create();
    display();
    delFromPos();
    display();
}