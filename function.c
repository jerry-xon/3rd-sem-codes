#include <stdio.h>
int getNum();
int main()
{
    int n;
    n = getNum();
    printf("Number: %d",n);
    return 0;
}
int getNum(){
    return 26;
}