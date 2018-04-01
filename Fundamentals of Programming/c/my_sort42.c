#include <stdio.h>

#define MAX 100

int main(void)
{
    int score[MAX];
    int count;
    int input;
    int i;
    int sorted;
    int minimum;
    int temp;

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
        score[count] = input;
        count++;
    }

    for (sorted = 0; sorted < count; sorted++) {
        minimum = sorted;
        for (i = sorted+1; i < count; i++) {
            if (score[i] < score[minimum]) {
	        minimum = i;
	    }
        }
        temp = score[minimum];
        score[minimum] = score[sorted];
        score[sorted] = temp;
    }

    for (i=0; i<count; i++) {
        printf("score[%d] : %d\n", i, score[i]);
    }

    return 0;
}
