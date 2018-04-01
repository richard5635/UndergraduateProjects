#include <stdio.h>

int main(void)

{
  int score;
  
  while (1) {
    printf("Input score >");
    scanf ("%d",&score);
    if (score==-1) {
      break;
    }
    printf("score: %d\n", score);
  }
  return 0;
}
