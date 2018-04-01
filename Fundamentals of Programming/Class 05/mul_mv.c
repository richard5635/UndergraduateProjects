#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int i, j, n;
    double *a, *ai, *b, *bi, *bj, *y, *yi;


    /*  input dimension n  */
    n=3;


    /*  allocate memory for A, x, and y  */
    a = (double *)malloc(n*n*sizeof(double));
    if (a==NULL) {
        printf("Can't allocate memory.\n");
        exit(1);
    }
    b = (double *)malloc(n*n*sizeof(double));//b is also 3x3
    if (b==NULL) {
        printf("Can't allocate memory.\n");
        exit(1);
    }
    y = (double *)malloc(n*n*sizeof(double));
    if (y==NULL) {
        printf("Can't allocate memory.\n");
        exit(1);
    }


    /*  input data of matrix A  */
    printf("\n");
    ai = a;
    for (i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%lf", ai + j);
        }
        ai += n;
    }


    /*  input data of matrix B  */
    printf("\n");
    bi = b;
    for (i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("b[%d][%d] = ", i, j);
            scanf("%lf", bi + j);
        }
        bi += n;
    }


    /*  print matrix A  */
    printf("\n  a =\n");
    ai = a;
    for (i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("    %.2f", *(ai + j));
        }
        ai += n;
        printf("\n");
    }


    /*  print matrix B  */
    printf("\n  b =\n");
    bi = b;
    for (i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("    %.2f", *(bi + j));
        }
        bi += n;
        printf("\n");
    }


    /*  calculate y = A*B  */
    ai = a;
    bi = b;
    yi = y;
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            *(yi + j) = 0.0;
            *(yi + j) += *(ai + j) * *(b+i);
            bi += n; //change rows for x
            //the matrix does not add on the same array
        }
        ai += n;
        bi -= n;
    }


    /*  print answer  */
    printf("\n  a*b = \n");
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            printf("    %.2f", *(yi + j));
        }
        printf("\n");
    }


    /*  free memory  */
    free(a);
    free(b);
    free(y);


    return 0;
}

//Result is
// 29       -2      17
// 12       18      22
// 16       -13     -7
