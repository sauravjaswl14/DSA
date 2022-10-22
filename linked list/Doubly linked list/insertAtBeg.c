#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head, *tail;

void createDLL()
{
    int choice=1;
    struct node *newnode;
    head=0;
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter data in node:");
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
        printf("\n do you want to continue?(0/1)");
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
    printf("\n total number of nodes: %d",count);
}

void insertAtbeg()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nenter data:");
    scanf("%d",&newnode->data);
    newnode->prev=0;
    newnode->next=0;
    head->prev=newnode;
    newnode->next=head;
    head=newnode;
}

void main()
{
    createDLL();
    display();
    insertAtbeg();
    display();
}