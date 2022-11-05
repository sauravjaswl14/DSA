#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *top=0;

void push(int x)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=top;
    top=newnode;
}

void display()
{
    struct node *temp;
    temp=top;
    if(top==0)
    {
        printf("list/stack is empty");
    }
    else{
        while(temp!=0)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}

void peek()
{
    if(top==0)
    {
        printf("list is empty!!");
    }
    else{
        printf("%d",top->data);
    }
}

void pop()
{
    struct node *temp;
    temp=top;
    if(top==0)
    {
        printf("underflow!!!");
    }
    else{
        printf("poped element is %d",top->data);
        top=top->next;
        free(temp);
    }
}

void main()
{
    int ch;
    do
    {
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
    } while (ch!=0);
    getch();  
}