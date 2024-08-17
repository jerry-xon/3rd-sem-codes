#include <stdio.h>

struct var_as_argument
{
    int x;
    int y;
};

void printvar(struct var_as_argument p){
    printf("%d %d\n", p.x,  p.y);
}

int main()
{
    struct var_as_argument p1 = {23, 45};
    struct var_as_argument p2 = {67, 89};
    printvar(p1);
    printvar(p2);
  return 0;
}