#include <stdio.h>
int main()
{
    float principal, rate, time, SI;
    printf("Enter principal amount: ");
    scanf("%f", &principal);
    printf("Enter rate of interest: ");
    scanf("%f", &rate);
    printf("Enter time period: ");
    scanf("%f", &time);
    SI = (principal*rate*time)/100;
    printf("Simple Interest = %.2f", SI);
  return 0;
}