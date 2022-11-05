#include<stdio.h>
#include<conio.h>
#define N 5
int stack[N];
int top=-1;

void push(int x)
{
    if(top==N-1)
    {
        printf("overflow!!");
    }
    else{
        top++;
        stack[top]=x;
    }
}

void pop()
{
    int item;
    if(top==-1)
    {
        printf("underflow!!");
    }
    else{
        item=stack[top];
        top--;
        printf("poped elemenr is %d",item);
    }
}

void peek()
{
    if(top==-1)
    {
        printf("stack is empty");
    }
    else{
        printf("the topmost element in the stack is: %d",stack[top]);
    }
}

void display()
{
    int i;
    for(i=top;i>=0;i--)
    {
        printf("%d\n",stack[i]);
    }
}

void main()
{
    int ch;
    do{
        printf("enter choice:- 1:push 2:pop 3:peek 4:display");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push(2);
                   break;
            case 2:pop();
                   break;
            case 3:peek();
                   break;
            case 4:display();
                   break;
            default: printf("invalid choice");                  
        }
    } while(ch!=0);
    getch();  
}