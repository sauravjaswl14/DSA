#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head,*temp;

void createDLL()
{
    int choice=1;
    struct node *newnode;
    head=0;
    while(choice)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("enter data in node:");
        scanf("%d",&newnode->data);
        newnode->prev=0;
        newnode->next=0;
        if(head==0)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
        printf("\ndo you want to continue adding nodes (0/1):?");
        scanf("%d",&choice);

    }
}
void display()
{
    int count=0;
    temp=head;
    while(temp!=0)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
        count++;
    }
    printf("\n total no. of nodes inserted: %d",count);
}
void main()
{
    createDLL();
    display();
    getch();
}