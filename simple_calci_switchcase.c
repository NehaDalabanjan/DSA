#include<stdio.h>
#include<stdlib.h>
int main()
{
    char ch;
    float a,b;
    while(1)
    {
        printf("enter the operator(+,-,*,/): ");
        scanf("%c",&ch);
        printf("enter the operands a and b: ");
        scanf("%f%f",&a,&b);
        switch(ch)
        {
        case'+':
            printf("%f + %f =%f\n",a,b,a+b);
            break;
        case'-':
            printf("%f - %f = %f",a,b,a-b);
            break;
        case'*':
            printf("%f*%f=%f",a,b,a*b);
            break;
        case'/':
            printf("%f/%f=%f",a,b,a/b);
            break;
        default:
            printf("invalid operator");
        }
        printf("\n");
    }
     printf("\n");
}
