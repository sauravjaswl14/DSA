#include<stdio.h>
#define N 5
int queue[N];
int front=-1;
int rear=-1;

void enqueue()
{
    int x;
    printf("enter element to be inserted in queue");
    scanf("%d",&x);
    if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=x;
    }
    else if(((rear+1)%N)==front)
    {
        printf("queue is full");
    }
    else{
        rear=(rear+1)%N;
        queue[rear]=x;
    }
}

void dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("underflow!!");
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else{
        printf("dequeued element is: %d",queue[front]);
        front=(front+1)%N;
    }
}

void display()
{
    int i=front;
    if(front==-1 && rear==-1)
    {
        printf("queue is empty");
    }
    else{
        while(i!=rear)
        {
            printf("%d\t",queue[i]);
            i=(i+1)%N;
        }
        printf("%d",queue[rear]);
    }
}

void main()
{
    enqueue();
    enqueue();
    enqueue();
    dequeue();
    dequeue();
    enqueue();
    display();
}
