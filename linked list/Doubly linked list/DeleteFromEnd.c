#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
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
    printf("\n total no. of nodes: %d\n",count);
}

void delFromEnd()
{
    struct node *temp;
    temp=tail;
    tail=tail->prev;
    tail->next=0;
    free(temp);
}
void main()
{
    create();
    display();
    delFromEnd();
    display();
    
}