#include <stdio.h>

struct point
{
    int x;
    int y;
};

void printvar(struct point *ptr){
    printf("%d %d\n", ptr->x,  ptr->y);
}

int main()
{
    struct point p1 = {23, 45};
    struct point p2 = {67, 89};
    printvar(&p1);
    printvar(&p2);
  return 0;
}