#include <stdio.h>

void input_data (void);
void sort_data (void);
void print_data (void);
void swap_data (int *a, int *b);
#define MAX 100


int score[MAX];
int count;
int *p;

void input_data(void)
{
    int input;

    count = 0;
    while (1) {
        printf("Input score > ");
        scanf("%d", &input);
        if (input == -1) {
            break;
        }
        if (count >= MAX) {
	    break;
        }
	*(score+count)=input;
	count++;

    }
}


void sort_data(void)
{
    int i, minimum, sorted, temp;

    for (sorted = 0; sorted < count; sorted++) {
        minimum = sorted;
        for (i = sorted+1; i < count; i++) {
	  if (*(score+i)< *(score+minimum)) {
	        minimum = i;
	    }
        }
	swap_data(score+minimum, score+sorted);
    }
}


void print_data(void)
{
  int i;

    for (i=0; i<count; i++) {
      printf("score[%d]..%d\n", i,*( score+i));
    }
}

void swap_data (int *a, int *b)
{
  int temp;

  temp= *a;
  *a= *b;
  *b= temp;
}
   
int main(void)
{
    input_data();
    sort_data();
    print_data();
    

    return 0;
}
