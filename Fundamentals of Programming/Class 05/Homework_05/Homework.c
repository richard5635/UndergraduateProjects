#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int i, j, k, n;
    double *a, *ai, *b, *bk, *bj, *y, *yi;
    
    
    /*  input dimension n  */
    n=3;
    
    
    /*  allocate memory for A, x, and y  */
    a = (double *)malloc(n*n*sizeof(double));
    if (a==NULL) {
        printf("Can't allocate memory.\n");
        exit(1);
    }
    b = (double *)malloc(n*n*sizeof(double));
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
    bk = b;
    for (k=0; k<n; k++) {
        for(j=0; j<n; j++) {
            printf("b[%d][%d] = ", k, j);
            scanf("%lf", bk + j);
        }
        bk += n;
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
    bk = b;
    for (k=0; k<n; k++) {
        for(j=0; j<n; j++) {
            printf("    %.2f", *(bk + j));
        }
        bk += n;
        printf("\n");
    }
    
    
    /*  calculate y = A*B  */
    ai = a;
    bk = b;
    yi = y;
    
    /* Sets everything inside the matrix A*B as 0 first */
    
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            *(yi+j) = 0.0;
        }
        yi +=n;
    }
    
    /* Multiplication Process */
    
    yi = y; //Resets y's position in the matrix back
    
    
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            for(k=0; k<n; k++)
            {
                *(yi+j) += *(ai+k) * *(bk+j);     //k corresponds to A's row transition and B's collumn transition
                bk += n;
            }
            bk -= 3*n;
        }
        ai += n;
        yi += n;
    }
    
    /*int i, j, k;
     for(i = 0; i < 3; i++)
     {
     for(j = 0; j < 3; j++)
     {
     for(k = 0; k < 3; k++)
     {
     result[i][j] +=  a[i][k] *  b[k][j];
     }
     }
     }*/
    
    
    yi=y;
    
    /*  print answer  */
    printf("\n  a*b = \n");
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            printf("    %.2f", *(yi + j));
        }
        printf("\n");
        yi += n;
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

//Question : is *(ai + j) affected by the i from the for function?

