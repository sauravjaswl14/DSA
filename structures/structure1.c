#include<stdio.h>

struct student
{
    int rollno;
    char name[20];
    float marks;
};

int main()
{
    struct student s1;
    struct student s2;
    printf("enter info for student 1:");
    scanf("%d %s %f",&s1.rollno,&s1.name,&s1.marks);
    printf("\nenter info for student 2:");
    scanf("%d %s %f",&s2.rollno,&s2.name,&s2.marks);
    printf("\n info of student1");
    printf("\n%d %s %f",s1.rollno,s1.name,s1.marks);
    printf("\n info of student2:");
    printf("\n%d %s %f",s2.rollno,s2.name,s2.marks);
}