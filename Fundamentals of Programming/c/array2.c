#include <stdio.h>

int main (void)
{
  int array [5];
  int *p;
  int i;
f
  for (i=0; i<5; i++) array [i]=i+10;
  for (p=&array[0]; 
for p!= &array [5]; p++) printf ("%d\n", *p);

  return 0;
}
