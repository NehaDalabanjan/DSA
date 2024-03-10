#include<stdio.h>
int main()
{
    char name[10];
    printf("Enter the name of max 10 characters: ");
    scanf("%s",name);
    printf("Input: %s\n",name);
    int len=strlen(name);
    for(int i=0,j=(len-1);i<=j;i++,j--)
    {
        char c=name[i];
        name[i]=name[j];
        name[j]= c;

    }
    printf("Reversed string is:%s ",name);
}
