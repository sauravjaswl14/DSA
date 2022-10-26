#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
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
        newnode->next=0;
        if(head==0)
        {
            head=tail=newnode;
            //tail->next=head;
        }
        else
        {
            tail->next=newnode;
            tail=newnode;
            //tail->next=head;
        }
        tail->next=head;
        printf("continue?(0/1)");
        scanf("%d",&choice);
    }
    printf("%d\n",tail->next->data);

}

void display()
{
    struct node *temp;
    temp=head;
    while(temp->next!=head)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
}

void main()
{
    create();
    display();
}