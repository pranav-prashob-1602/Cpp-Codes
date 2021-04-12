#include <stdio.h>

struct name {
    int i;
    float f;
}d;

int main()
{
   d.i = 4;
   d.f = 3.67874;
   printf("%d %.2f",d.i,d.f);

   return 0;
}
