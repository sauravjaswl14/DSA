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
        printf("enter data in a node:");
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

/*int getLength()
{
    int count=0;
    struct node *temp;
    temp=tail->next;
    while(temp!=tail)
    {
        count++;
        temp=temp->next;
    }
    printf("%d",count);
    return count;
}*/

void insertAtpos()
{
    int pos,i=1;
    struct node *newnode,*temp;
    printf("\nenter position:");
    scanf("%d",&pos);
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nenter data:");
    scanf("%d",&newnode->data);
    newnode->next=0;
    temp=tail->next;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}

void main()
{
    create();
    display();
    insertAtpos();
    display();
}