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
        printf("continue?(0/1)");
        scanf("%d",&choice);
    }
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
    printf("no. of nodes:%d",count);
    return count;
}

void deleteFromPos()
{
    int pos,i=1,l;
    struct node *temp;
    temp=head;
    printf("\nenter position of node to be deleted");
    scanf("%d",&pos);
    l=getLength();
    if(head==0)
    {
        printf("list is empty");
    }
    else if(pos<1||pos>l)
    {
        printf("\ninvalid position");
    }
    else{
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        if(temp->next==head)
        {
            tail=temp->prev;
            free(temp);
        }
        else{
            free(temp);
        }
    }
}

void main()
{
    create();
    display();
    deleteFromPos();
    display();
}