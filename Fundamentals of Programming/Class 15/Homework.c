#include <stdio.h>
#include <stdlib.h>
#define STACK_MAX 10

char path[STACK_MAX];
int stack_top = 0;

void stack_push(char a)
{
    if(stack_top == STACK_MAX)
    {
        printf("stack: overflow\n");
        exit(1);
    }
    path[stack_top] = a;
    stack_top++;
}

int stack_pop()
{
    if(stack_top == 0)
    {
        printf("stack : underflow\n");
        exit(1);
    }
    stack_top--;
    return path[stack_top];
}

int main()
{
	int i,j,k;
  	char data[7][5]={"ABDI","ABEJ","ABEKO","ACF","ACGL","ACHMO","ACHN"};
	char start, end;
    

  	printf("Please select your path (Needs to be from A): ");
  	scanf("from %c to %c", &start, &end);
  	
  
    
    for(i=0; i<7; i++)
    {
        for(j=0; j<5; j++)
        {
            if( data[i][j] == end)
            {
                for(k=j; k>-1; k--) //Going backwards
                {
                    stack_push(data[i][k]);
                    if( data[i][k] == start)
                    {
                        while(stack_top > 0)
                        {
                            printf("->");
                            printf("%c",stack_pop());
                        }
                        printf("\n");
                    }
                }
            }
        }
    }
    

    
    return 0;
}

//References
/*
 
 https://www.youtube.com/watch?v=MuwxQ2IB8lQ
 
 */