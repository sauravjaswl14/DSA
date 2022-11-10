#include<stdio.h>
#define N 5
int stack1[N];
int stack2[N];
int top1=-1;
int top2=-1;
int count=0;

void push1(int data)
{
    if(top1==N-1)
    {
        printf("stack1 is full");
    }
    else{
        top1++;
        stack1[top1]=data;
    }
}

void push2(int data)
{
    if(top2==N-1)
    {
        printf("stack2 is full");
    }
    else{
        top2++;
        stack2[top2]=data;
    }
}

int pop1()
{
    if(top1==-1)
    {
        printf("stack1 is empty");
    }
    else{
        return stack1[top1--];
    }
}

int pop2()
{
    if(top2==-1)
    {
        printf("stack2 is empty");
    }
    else{
        return stack2[top2--];
    }
}

void enqueue(int x)
{
    push1(x);
    count++;
}

void dequeue()
{
    int i,a,b;
    if(top1==-1 && top2==-1)
    {
        printf("stack is empty");
    }
    else{
        for(i=0;i<count;i++)
        {
            a=pop1();
            push2(a);
        }
        b=pop2();
        printf("dequeued element is %d",b);
        count--;
        for(i=0;i<count;i++)
        {
            a=pop2();
            push1(a);
        }
    }
}

void display()
{
    int i;
    printf("the queue is:");
    for(i=0;i<=top1;i++)
    {
        printf("%d\t",stack1[i]);
    }
}

void main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    dequeue();
    display();
}