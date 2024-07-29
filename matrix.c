#include <stdio.h>
int main()
{
    int r1, c1;
    int r2,c2;
    int a[10][10];
    int b[10][10];

    scanf("enter row: %d",&r1);
    scanf("enter row: %d",&c1);
    for(int i=0; i<=r1; i++){
        scanf("Enter element of row: %d",a[i]);
        for(int j=0;j<=c1;j++){
            scanf("Enter element of column: %d",a[j]);
            
        }
    }
  return 0;
}