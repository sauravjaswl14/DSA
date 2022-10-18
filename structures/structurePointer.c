#include<stdio.h>

struct student
{
    int rollno;
    char name[20];
    float marks;
};

struct student s;

void main()
{
    struct student *ptr =&s;
    printf("enter info for student s:");
    scanf("%d %s %f",&ptr->rollno,&ptr->name,&ptr->marks);
    printf("\nstudent info:");
    printf("\n%d %s %f",(*ptr).rollno,ptr->name,ptr->marks);
}