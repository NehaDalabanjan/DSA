//right half pyramid
/*#include<stdio.h>
int main()
{
    int row=5;
    for (int i=0;i<row;i++)
    {
        for(int j=0;j<=i;j++)
        {
           printf("*");
        }
        printf("\n");
    }
    return 0;
}
*/

//left half pyramid
/*#include<stdio.h>
int main()
{
    int row=5;
    for (int i=0;i<row;i++)
    {
        for(int j=0;j<=row-i-1;j++)
        {
           printf(" ");
        }
          for(int j=0;j<=i;j++)
        {
           printf("*");
        }
        printf("\n");
    }
    return 0;
}
*/
//full pyramid
/*#include<stdio.h>
int main()
{
    int row=5;
    for (int i=0;i<row;i++)
    {
        for(int j=0;j<=row-i-1;j++)
        {
           printf(" ");
        }
          for(int j=0;j<=i;j++)
        {
           printf("*");
        }
            for(int j=0;j<i;j++)
        {
           printf("*");
        }
            for(int j=0;j<=row-i-1;j++)
        {
           printf(" ");
        }
        printf("\n");
    }
    return 0;
}
*/
/*#include<stdio.h>
int main()
{
    int row=5;
    for (int i=0;i<=row;i++)
    {
        for(int j=0;j<row-i+1;j++)
        {
           printf("*");
        }
        printf("\n");
    }
    return 0;
}
/*

#include<stdio.h>
int main()
{
    int row=5;
    for (int i=0;i<=row;i++)
    {
        for(int j=0;j<row-i+1;j++)
        {
           printf("*");
        }
        printf("\n");
    }
    return 0;
}
