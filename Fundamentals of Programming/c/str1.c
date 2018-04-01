#include <stdio.h>

int main(void)
{
  char ch1, ch2, ch3;

  ch1='A'; ch2='B'; ch3='C';

  printf("%c...%d\n", ch1,ch1);
  printf("%c...%d\n", ch2,ch2);
  printf("%c...%d\n", ch3,ch3);

  printf("%c\n", ch1+1);
  printf("%c\n", ch1+32);

  return 0;
}

