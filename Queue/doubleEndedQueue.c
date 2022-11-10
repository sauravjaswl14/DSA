#include<stdio.h>
#define N 5
int deque[N];
int front=-1, rear=-1;

void enqueueFront(int x)
{
    if((front==0 && rear==N-1) || (front==rear+1)) //else if(((rear+1)%N)==front)
    {
        printf("queue is full");
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        deque[front]=x;
    }
    else if(front==0)
    {
        front=N-1;
        deque[front]=x;
    }
    else{
        front--;
        deque[front]=x;
    }
}

void enqueueRear(int x)
{
    if((front==0 && rear==N-1) || (front==rear+1))
    {
        printf("queue is full");
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        deque[rear]=x;
    }
    else if(rear==N-1)
    {
        rear=0;
        deque[rear]=x;
    }
    else{
        rear++;
        deque[rear]=x;
    }
}

void display()
{
    int i=front;
    if(front==-1 && rear==-1)
    {
        printf("queue is empty");
    }
    while(i!=rear)
    {
        printf("%d\t",deque[i]);
        i=(i+1)%N;
    }
    printf("%d",deque[rear]);
}

void getFront()
{
    if(front==-1 && rear==-1)
    {
        printf("queue is empty");
    }
    else{
        printf("element at front is: %d",deque[front]);
    }
}

void getRear()
{
    if(front==-1 && rear==-1)
    {
        printf("queue is empty");
    }
    else{
        printf("element at rear is: %d",deque[rear]);
    }
}

void dequeueFront()
{
    if(front==-1 && rear==-1)
    {
        printf("queue is empty");
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else if(front==N-1)
    {
        front=0;
    }
    else{
        printf("dequeued element is: %d",deque[front]);
        front++;
    }
}

void dequeueRear()
{
    if(front==-1 && rear==-1)
    {
        printf("queue is empty");
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else if(rear==0)
    {
        rear=N-1;
    }
    else{
        printf("dequeued element is: %d",deque[rear]);
        rear--;
    }
}

void main()
{
    enqueueFront(2);
    enqueueFront(5);
    enqueueRear(-1);
    enqueueRear(0);
    enqueueFront(7);
   // enqueueFront(4);
    display();
}