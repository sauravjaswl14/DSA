#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head,*tail;

void create()
{
    int choice=1;
    head=0;
    struct node *newnode;
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter data:");
        scanf("%d",&newnode->data);
        if(head==0)
        {
            head=tail=newnode;
            newnode->next=head;
            newnode->prev=tail;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            newnode->next=head;
            head->prev=newnode;
            tail=newnode;
        }
        printf("continue?(0/1):");
        scanf("%d",&choice);
    }
}

void display()
{
    struct node *temp;
    temp=head;
    while(temp!=tail)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
}

void deleteFromBeg()
{
    struct node *temp;
    temp=head;
    if(head==0)
    {
        printf("list is empty");
    }
    else if(head->next==head)
    {
        head=tail=0;
        free(temp);
    }
    else{
        head=head->next;
        head->prev=tail;
        tail->next=head;
        free(temp);
    }
}

void main()
{
    create();
    display();
    deleteFromBeg();
    display();
}