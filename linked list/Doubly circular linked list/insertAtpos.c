#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
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
        printf("continue?(0/1):");
        scanf("%d",&choice);
    }
}

void insertAtBeg()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nenter data in newnode:");
    scanf("%d",&newnode->data);
    if(head==0)
    {
        head=tail=newnode;
        head->next=head;
        head->prev=head;
    }
    else
    {
        head->prev=newnode;
        newnode->next=head;
        newnode->prev=tail;
        tail->next=newnode;
        head=newnode;

    }
}


int getLength()
{
    int count=0;
    struct node *temp;
    temp=head;
    while(temp!=tail)
    {
        count++;
        temp=temp->next;
    }
    count++;
   // printf("\ntotal nodes:%d",count);
    return count;
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
    // getLength();
}


void insertAtpos()
{
 int pos,i=1,l;
 struct node *temp,*newnode;
 temp=head;
 printf("\nenter position where you want to enter a node:");
 scanf("%d",&pos);
 l=getLength();
 if(pos<1 || pos>l)
 {
    printf("invalid position\n");
 }
 else if(pos==1)
 {
    insertAtBeg();
 }
 else{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nenter data in new node:");
    scanf("%d",&newnode->data);
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next->prev=newnode;
    newnode->prev=temp;
    temp->next=newnode;
 }

}

void main()
{
    create();
    display();
    insertAtpos();
    display();
}