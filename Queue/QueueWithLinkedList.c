#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front=0;
struct node *rear=0;

void enqueue(int x)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=0;
    if(front==0 && rear==0)
    {
        front=rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}

void display()
{
    struct node *temp;
    if(front==0 && rear==0)
    {
        printf("Queue is empty");
    }
    else{
        temp=front;
        printf("queue is: ");
        while(temp!=0)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}

void dequeue()
{
    struct node *temp;
    temp=front;
    if(front==0 && rear==0)
    {
        printf("queue is empty");
    }
    else if(front==rear)
    {
        front=rear=0;
        free(temp);
    }
    else{
        printf("dequeued element is: %d",front->data);
        front=front->next;
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
        printf("topmost element in queue is: %d",front->data);
    }
}

void main()
{
    int ch;
    do{
        printf("\nenter choice:- 1:enqueue 2:dequeue 3:peek 4:display");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: enqueue(5); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: display(); break;
            default: printf("invalid choice");
        }
    }while(ch!=0);
}
