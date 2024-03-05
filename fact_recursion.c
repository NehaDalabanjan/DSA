#include<stdio.h>
int main()
{
    int n=5;
    int fact1= factorial(n);
    printf("factorial of no is %d: %d\n",n,fact1);
    return 0;

}
int factorial(int n)
{
    if(n==0|n==1)
    {
        return 1;
    }
    else {
        return n*factorial(n-1);
    }

}
