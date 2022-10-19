#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head,*newnode,*temp;
void createLL()
{
    int choice,count=0;
    head=0;
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter data:");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0)
        {
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        printf("do you want to continue(0/1)?");
        scanf("%d",&choice);
    }
    temp=head;
    while(temp!=0)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
        count++;
    }
    printf("\ntotal no. of nodes created: %d",count);
    getch();
}
void main()
{
    int count=0;
    createLL();
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nenter data:");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
    temp=head;
    while(temp!=0)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
        count++;
    }
    printf("\ntotal no.of nodes created: %d",count);
    getch();

}