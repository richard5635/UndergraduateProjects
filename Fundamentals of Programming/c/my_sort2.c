#include<stdio.h>

int main(void)
{
  int score [100];
  int count;
  int input;
  int i;

  count=0;
  while (1) {
    printf ("input score > ");
    scanf("%d", &input);
    if (input==-1) {
      break;
    }
    score [count]=input;
    count++;
  }
  i=0;
  while (i < count) {
    printf("score[%d] : %d\n", i, score [i]);
    i++;
  }

  return 0;
}
