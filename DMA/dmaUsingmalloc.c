#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,n,*ptr;
    printf("enter number of values you are going to store:\t");
    scanf("%d",&n);
    ptr=(int*)malloc(n*sizeof(int));
    printf("enter the numbers:");
    for(i=0;i<n;i++)
    {
        scanf("%d",ptr+i);
    }
    printf("\n the values are :");
    for(i=0;i<n;i++)
    {
        printf("%d\t",*(ptr+i));
    }
    free(ptr);
}