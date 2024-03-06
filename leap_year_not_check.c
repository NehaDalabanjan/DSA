//modulas operator returns remainder leap years 1988,1992,1996
#include<stdio.h>
int main()
{
    int year;
    printf("enter the year:  ");
    scanf("%d",&year);
    if(year%400==0)
        printf("Year is a leap year");
    else if(year%4==0)
        printf("Year is a leap year");
    else
        printf("Year is not leap year");

}
