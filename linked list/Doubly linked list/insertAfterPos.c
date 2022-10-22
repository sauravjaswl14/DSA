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
        printf("enter data :");
        scanf("%d",&newnode->data);
        newnode->next=0;
        newnode->prev=0;
        if(head==0)
        {
            head=tail=newnode;
        }
        else
        {
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
        printf("continue?(0/1)");
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
    printf("\ntotal no. of nodes: %d",count);
}
void insertAfterPos()
{
    int pos,i=1;
    struct node *temp;
    temp=head;
    printf("enter position after which u want to insert:");
    scanf("%d",&pos);
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\n insert data in a node");
    scanf("%d",&newnode->data);
    while(i<pos)
    {
        temp=temp->next;
        i++;
    }
    newnode->prev=temp;
    newnode->next=temp->next;
    temp->next=newnode;
    newnode->next->prev=newnode;
}
   

void main()
{
    create();
    display();
    insertAfterPos();
    display();
}