#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head,*newnode,*temp;
int create()
{
    int choice,count=0;
    head=0;
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter data in a node:");
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
        printf("continue?(0/1)");
        scanf("%d",&choice);
    }
    temp=head;
    while(temp!=0)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
        count++;
    }
    printf("\ntotal number of node: %d",count);
    return count;

}
void main()
{
    int pos,count,i=1;
    count=create();
    printf("\nenter position after which you want to insert a node:");
    scanf("%d",&pos);
    if(pos>count)
    {
        printf("invalid position");
    }
    else
    {
        temp=head;
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nenter data in a node:");
        scanf("%d",&newnode->data);
        newnode->next=temp->next;
        temp->next=newnode;
    }
        temp=head;
        count=0;
        while(temp!=0)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
            count++;
        }
        printf("\ntotal number of node: %d",count);

    getch();
}