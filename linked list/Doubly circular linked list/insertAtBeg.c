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
            head->next=head;
            head->prev=head;
        }
        else
        {
            tail->next=newnode;
            newnode->prev=tail;
            newnode->next=head;
            head->prev=newnode;
            tail=newnode;
        }
        printf("continue adding nodes?(0/1):");
        scanf("%d",&choice);
    }
    printf("%d\n",tail->next->data);
    printf("%d\n",head->prev->data);
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

void insertAtBeg()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nenter data in newnode:");
    scanf("%d",&newnode->data);
    if(head==0)
    {
        head=tail=newnode;
        head->next=head;
        head->prev=head;
    }
    else
    {
        head->prev=newnode;
        newnode->next=head;
        newnode->prev=tail;
        tail->next=newnode;
        head=newnode;

    }
}

void main()
{
    create();
    display();
    insertAtBeg();
    display();
}