#include<stdio.h>
int check_prime(int i,int num);
int main()
{   int num;
    printf("enter the num: ");
    scanf("%d",&num);
    if (check_prime(2,num)==0)
       printf("Its a prime no");
    else
        printf("Not a prime no");
}
int check_prime(int i,int num)
{
    if(num==i)
        return 0;
    else
        if(num%i==0)
        return 1;
    else{
        return check_prime(i+1,num);
    }

}
