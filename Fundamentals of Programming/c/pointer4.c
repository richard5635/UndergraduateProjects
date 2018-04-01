#include <stdio.h>

int main (void)
{
  int a;
  int *p_a;
  double b;
  double *p_b;

  p_a= &a;
  printf("p_a...%p\n", p_a);
  p_a++;
  printf("p_a...%p\n", p_a);

  p_b=&b;
  printf("p_b...%p\n", p_b);
  p_b++;
  printf("p_b...%p\n", p_b);

  return 0;
}

