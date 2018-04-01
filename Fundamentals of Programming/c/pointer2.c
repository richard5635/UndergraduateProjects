#include <stdio.h>

int main (void)
{
  int x=3;
  int *x_p;

  x_p= &x;
  printf("value.. %d, pointer.. %p\n", x, &x);
  printf("value.. %d, pointer.. %p\n",*x_p, x_p);

  return 0;
}

