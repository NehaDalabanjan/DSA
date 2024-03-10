#include<stdio.h>
float temp_celcius,temp_farh,temp_kelvin;
int main()
{
printf("enter the temperature in celcius : ");
scanf("%f",&temp_celcius);
temp_kelvin=temp_celcius+273.15;
printf("Temperature in kelvin is=%f\n",temp_kelvin);
temp_farh=(temp_celcius*1.8)+32;
printf("Temperature in fahreheit=%f",temp_farh);
}
