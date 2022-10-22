#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head, *tail;

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
        printf("\ncontinue?(0/1)");
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
    printf("\ntotal no. of nodes inserted: %d",count);
}

void insertAtpos()
{
    int pos,i=1;
    printf("\nenter the position where u want to insert:");
    scanf("%d",&pos);
    struct node *temp;
    struct node *newnode;
    temp=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\ninsert data in a node:");
    scanf("%d",&newnode->data);
   
    while(i<pos-1)
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
    insertAtpos();
    display();
}