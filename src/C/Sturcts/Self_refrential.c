#include <stdio.h>

struct Self
{
    int a;
    char c;
    struct Self *ptr;
};

int main()
{
    struct Self var1 ,var2;
    var1.c = 'A';
    var1.a = 10;
    var1.ptr = NULL;

    var2.a = 20;
    var2.c = 'B';
    var2.ptr = NULL;

    var1.ptr = &var2;
    printf("%d %c\n%d %c", var1.ptr->a, var1.ptr->c, var2.a, var2.c );
  return 0;
}