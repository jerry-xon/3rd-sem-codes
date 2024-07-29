#include <stdio.h>
int main()
{
    float principal, rate, time, CI;
    printf("Enter principal amount: ");
    scanf("%f", &principal);
    printf("Enter rate of interest: ");
    scanf("%f", &rate);
    printf("Enter time period: ");
    scanf("%f", &time);
    CI = principal * (pow((1 + rate / 100), time));
    printf("Compound Interest = %f", CI);

 return 0;
}