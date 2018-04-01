#include <stdio.h>

void swap (int a, int b)
{
  int temp;

  temp=a;
  a=b;
  b=temp;
}

 int main (void)
 {
   int x=3;
   int y=5;

   printf( "x..%d, y..%d/n", x, y);
   swap (x,y);
   printf("x..%d, y..%dn", x, y);

   return 0;
 }

