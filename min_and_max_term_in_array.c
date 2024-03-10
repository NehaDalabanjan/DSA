#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void read(int a[MAX],int m);
void find_min_max(int a[MAX],int m);

int main()
{   int a[MAX];
    int m;
    if(m<=0)
    {
        printf("no of elements are negative ");
    }
    else if(m>MAX)
        printf("no of elements cant be greater than max");
    else{
        printf("enter the no of array elements : ");
        scanf("%d",&m);
        read(a,m);
        find_min_max(a,m);
    }
}
void read(int a[MAX],int m)
{
    int i;
    for(i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
    }
}

void find_min_max(int a[MAX],int m)
{
    int max=a[0];
    int min=a[0];
    int i;
    for(int i=0;i<m;i++)
    {
        if(a[i]>max)
        {
            max = a[i];
        }
        else if(a[i]<max)
        {
            min = a[i];
        }
    }
   printf("MAX ELEMENT IS: %d\n",max);
   printf("MIN ELEMENT IS: %d",min);
}
