#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head;

void create()
{
    int choice;
    head=0;
    struct node *newnode,*temp;
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter data in a node:");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0)
        {
            head=temp=newnode;    
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        printf("continue?(0/1):");
        scanf("%d",&choice);
    }
}

void display()
{
    int count=0;
    struct node *temp;
    temp=head;
    while(temp!=0)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
        count++;
    }
    printf("\ntotal no. of nodes are: %d",count);
}

void reverseSLL()
{
    struct node *prevnode,*currentnode,*nextnode;
    prevnode=0;
    currentnode=nextnode=head;
    while(nextnode!=0)
    {
        nextnode=nextnode->next;
        currentnode->next=prevnode;
        prevnode=currentnode;
        currentnode=nextnode;
    }
    head=prevnode;
}

void main()
{
    create();
    display();
    reverseSLL();
    display();
}