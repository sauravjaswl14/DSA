#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head,*temp,*newnode;
void createLinkedList()
{
    int choice;
    head=0;
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("insert a data:");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        printf("\nDo you want to continue:(0/1)?");
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
    printf("\ntotal no.of nodes are: %d",count);
}
void DeleteFromEnd()
{
    struct node *prevnode;
    temp=head;
    while(temp->next!=0)
    {
        prevnode=temp;
        temp=temp->next;
    }
    prevnode->next=0;
    free(temp);
}

void main()
{
    createLinkedList();
    display();
    DeleteFromEnd();
    display();
}