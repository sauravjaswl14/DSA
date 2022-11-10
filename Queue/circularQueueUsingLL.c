#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front=0;
struct node *rear=0;

void enqueue()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data in queue: ");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(front==0 && rear==0)
    {
        front=rear=newnode;
        rear->next=front;
    }
    else{
        rear->next=newnode;
        rear=newnode;
        rear->next=front;
    }
}

void dequeue()
{
    struct node *temp;
    temp=front;
    if(front==0 && rear==0)
    {
        printf("Queue is empty");
    }
    else if(front==rear)
    {
        front=rear=0;
        free(temp);
    }
    else{
        printf("\ndequeued element is: %d",front->data);
        front=front->next;
        rear->next=front;
        free(temp);
    }
}

void peek()
{
    if(front==0 && rear==0)
    {
        printf("queue is empty");
    }
    else{
        printf("\ntop element is: %d",front->data);
    }
}

void display()
{
    struct node *temp;
    temp=front;
    if(front==0 && rear==0)
    {
        printf("queue is empty");
    }
    while(temp->next!=front)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
}

void main()
{
    enqueue();
    enqueue();
    enqueue();
    enqueue();
    dequeue();
    dequeue();
    peek();
    display();
}