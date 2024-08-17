// this program is about passing array of structures as argument
#include <stdio.h>
struct point
{
    int x;
    int y;
};

void printarr(struct point p[])
{
    for(int i = 0; i <= 1; i++){
        printf("%d %d\n", p[i].x, p[i].y);
    }
  
}

int main()
{
    struct point arr[2] = {{1, 3}, {2, 9}};
    printarr(arr);
    return 0;
}