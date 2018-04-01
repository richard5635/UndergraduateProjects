#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i,j,n;
	double *a, *ai, *x, *y;
	
	printf(" n: ");
	scanf("%d",&n);	
	
	a=(double *)malloc(n*n*sizeof(double));
	if(a==NULL)
	{
		printf("Can't allocate memory for a. \n");
		exit(1);
	}
	x=(double *)malloc(n*sizeof(double));
	if(x==NULL)
	{
		printf("Can't allocate memory for x. \n");
		exit(1);
	}
	y=(double *)malloc(n*sizeof(double));
	if(y==NULL)
	{
		printf("Can't allocate memory for y. \n");
		exit(1);
	}
	
	ai=a; 
	//ai = The address of a[0][0]
	//a  = The address of 1st memory allocated by malloc (size)
	

	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("a[%d][%d] = ",i,j);
			scanf("%lf", ai+j);
		}
		ai+=n; //Adds n to j
	}
	
	for(i=0;i<n;i++)
	{
		printf("x[%d] = ",i);
		scanf("%lf", x+i);	//No need to put & mark if it is a pointer
	}
	
	for(i=0;i<n;i++)
	{
		*(y+i)=0;
	}	
	
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			*(y+i)+=*(ai+j)**(x+i);
		}
		ai+=n;
	}
	
	printf("A*x =\n");
	for(i=0;i<n;i++)
	{
		printf("%.2f\n", *(y+i));
	}
	
	free(a);
	free(x);
	free(y);
	
	return 0;
	
}