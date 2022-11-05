#include<stdio.h>
#define N 5
int queue[N];
int front=-1;
int rear=-1;

void enqueue(int x)
{
    if(rear==N-1)
    {
        printf("overflow!!");
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=x;
    }
    else{
        rear++;
        queue[rear]=x;
    }
}

void dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("queue is empty");
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else{
        printf("dequeued element is: %d",queue[front]);
        front++;
    }
}

void display()
{
    int i;
    if(front==-1 && rear==-1)
    {
        printf("queue is empty");
    }
    else{
        for(i=front;i<rear+1;i++)
        {
            printf("%d",queue[i]);
        }
    }
}

void peek()
{
    if(front==-1 && rear==-1)
    {
        printf("list is empty");
    }
    else{
        printf("topmost element is %d",queue[front]);
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
