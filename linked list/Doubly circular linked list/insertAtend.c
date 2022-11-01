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
    struct node *newnode;
    head=0;
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

void insertAtEnd()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nenter data in newly created node:");
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
}

void main()
{
    create();
    display();
    insertAtEnd();
    display();
}