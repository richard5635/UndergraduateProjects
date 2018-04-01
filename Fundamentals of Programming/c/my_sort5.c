#include<stdio.h>
#define MAX 100
int main(void)
{
  int score[MAX];
    int count;
    int input;
    int i;
    int unsorted;
   
    int temp;


    count=0;
    while(1) {
    printf ("input score> ");
      scanf("%d", &input);
      if (input == -1) {
	break;
      }
      if (count >= MAX) {
      printf ("the number of inputs is more than Max,STOP\n> ");
	break;
      }
      score [count]= input;
      count++;
    }
    
 for (unsorted=0; unsorted< count; unsorted++)
    for (i=unsorted+1; i< count; i++) {
      if (score[i] < score[unsorted]) {
	 temp= score [i];
    score[i]=score[unsorted];
    score[unsorted]=temp;
}
     
   
}


    for (i=0; i< count; i++){
    printf ("score[%d] : %d\n", i, score[i]);

  }
    return 0;
}
