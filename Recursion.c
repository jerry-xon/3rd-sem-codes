#include <stdio.h>

int getF();
int main()
{
    int f;
    f = getF();
    printf("Factorial: %d", f);
    return 0;

}

int getF(){
    int n, i;
    int fact = 1;
    printf("Enter a number: ");
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        fact = fact * i;
    }
    return fact;
}