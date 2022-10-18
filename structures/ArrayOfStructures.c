#include<stdio.h>

struct student
{
    int rollno;
    char name[20];
    float marks;
};

void main()
{
    int i;
    struct student s[3];
    printf("enter info of students:");
    for(i=0;i<3;i++)
    {
        scanf("%d %s %f",&s[i].rollno,&s[i].name,&s[i].marks);
    }
    printf("\nstudents info:");
    for(i=0;i<3;i++)
    {
        printf("%d %s %f\n",s[i].rollno,s[i].name,s[i].marks);
    }
}