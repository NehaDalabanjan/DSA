#include<stdio.h>
 float price;
 float discounted_amt;
 float discount_price;
 float discount_percentage;
 int main(){
 printf("Enter Price of Item  : ");
 scanf("%f", &price);
 printf("Enter Discount Percentage on Item  : ");
 scanf("%f", &discount_percentage);
 discount_price=(discount_percentage*price)/100;
 discounted_amt=(price-discount_price);
 printf("the discounted price is =%f\n",discount_price);
 printf("the amt to be paid is =%f\n\n",discounted_amt);
 return 0;
 }
