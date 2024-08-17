// this program is about returning a pointer to structure from a function 
#include <stdio.h>
#include <stdlib.h>

struct point
{
  int x;  
  int y;
};

struct point* fun(int a, int b){
  struct point* p = (struct point*)malloc(sizeof(struct point));
  p->x = a;
  p->y = b + 5;
  return p;
}

void printvar(struct point *p){
  printf("%d %d\n", p->x , p->y);
 
}
int main()
{
  struct point *ptr1 , *ptr2;
  ptr1 = fun(10,5);
  ptr2 = fun(3,9);
  printvar(ptr1);
  printvar(ptr2);
  free(ptr1);
  free(ptr2);
  return 0;

  return 0;
}