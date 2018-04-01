#include <stdio.h>

int sa( int x, int y)
 
{
  int z;
  z=x-y;
  return z;
}
int seki(int x, int y)
{
  int z;
  z=x*y;
  return z;
}
int main (void)
{
  int a,b,difference, product;

  printf("a="); scanf ("%d", &a);
  printf("b="); scanf ("%d", &b);
  difference= sa(a,b);
  product=seki(a,b);
  printf( "a-b= %d\n", difference);
 printf( "a*b= %d\n", product);
 
  return 0;
}
