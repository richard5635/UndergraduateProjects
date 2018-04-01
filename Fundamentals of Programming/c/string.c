#include <stdio.h>

int main ( void)
{
  char str[64];
  int i;

  printf("Input a string; ");
  scanf("%s", str);

  i=0;
  while (str[i] != '\0') {
    i++;
  }

  printf ("%d letters. \n", i);
  return 0;
}
