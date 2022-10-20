#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head,*temp,*newnode;

void create()
{
    int choice;
    head=0;
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data in node:");
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
        printf("\n continue(0/1)?");
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
    printf("total no. of nodes: %d",count);
}
void deleteFromPos(){
    int pos,i=1;
    struct node *nextnode;
    temp=head;
    printf("enter position:");
    scanf("%d",&pos);
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    nextnode=temp->next;
    temp->next=nextnode->next;
    free(nextnode);
}
void main()
{
    create();
    display();
    deleteFromPos();
    display();
    getch();
}