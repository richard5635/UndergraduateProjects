#include <stdio.h>


int main(void)
{
    int i, j;
    double x[3] = {-33.0, 9.0, 6.0}; 
    double y[3];
    double a[3][3] = {{2.0, 4.0, 6.0}, 
                      {3.0, 8.0, 7.0}, 
		      {5.0, 7.0, 21.0}};
    double *ai;


    ai = a;
    for (i=0; i<3; i++) {
        *(y + i) = 0.0;
        for (j=0; j<3; j++) {
	    *(y + i) += *(ai + j) * *(x + j);
        }
        ai += 3;
    }


    printf("y = \n");
    for (i=0; i<3; i++) {
        printf("%6.2f\n", *(y + i));
    }


    return 0;
}
