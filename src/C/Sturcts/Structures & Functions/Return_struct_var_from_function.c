// this program is about returning a structure variable from a funtion.

#include <stdio.h>

struct point
{
    int x;
    int y;
};

struct point edit(struct point ptr){
    (ptr.x)++;
    ptr.y += 5;
    return ptr;
}
void printvar(struct point p){
    printf("%d %d\n", p.x,  p.y);
}
int main()
{
    struct point p1 = {44,70};
    struct point p2 = {99 ,25};
    p1 = edit(p1);
    p2 = edit(p2);
    printvar(p1);
    printvar(p2);

  return 0;
}