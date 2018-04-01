#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i,n;
	double *x;
	
	
	c
	
	//x is opened
	x=(double*)malloc(n*sizeof(double)); //Opens up memory with the size of n times the variable type
	if(x==NULL)
	{
		printf("Can't allocate memory.\n");
		exit(1);
	}
	
	for(i=0;i<n;i++)
	{
		printf("x[%d]= ",i);
		scanf("%lf", x+i); 
	}
	
	printf("\n x=\n");
	for(i=0;i<n;i++)
	{
		printf("%.2f\n", *(x+i));
	}
	
	//x is closed
	free(x);
	
	
	return 0;
	
}
	