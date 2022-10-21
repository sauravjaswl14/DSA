#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head,*temp,*newnode;
void createList(){
    int choice;
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
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        printf("Do you want to continue with creating more nodes?(0/1):");
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
    printf("\n total nodes inserted are: %d",count);
}

void DelfromBeg()
{
    temp=head;
    head=head->next;
    free(temp);
}

void main()
{
    createList();
    display();
    DelfromBeg();
    display();

}