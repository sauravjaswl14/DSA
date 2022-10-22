#include<stdio.h>
#include<conio.h>
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

        printf("\nDo you want to continue?(0/1)");
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
    printf("\ntotal number of nodes created: %d",count);
}
void main()
{
    create();
    display();
   
}