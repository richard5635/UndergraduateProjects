#include <stdio.h>

int main (void)
{
  int a=123, b;
  int *p;

  p= &a;
  b= *p;
  printf("a=%d, b=%d, *p=%d\n", a, b, *p);

  a=200;
  b=300;
 printf("a=%d, b=%d, *p=%d\n", a, b, *p);
 
 p=&b;
  printf( "a=%d, b=%d, *p=%d\n", a,b,*p);
  return 0;
}
