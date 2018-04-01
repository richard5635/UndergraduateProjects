//
//  factorial.c
//  
//
//  Created by Richard Sahala Hartanto on 12/6/13.
//
//

#include <stdio.h>

int factorial( int x)
{
    int xx;
    if((xx=0 || x==1))
    {
        printf("1");
        return 1;
    }
    else
    {
        printf("%d * (", x);
        xx = x * factorial (x-1);
        printf(")");
        return xx;
    }
}

int main()
{
    int number;
    int value;
    printf("Factorial Calculator\n\nFactorial of : ");
    scanf("%d", &number);
    value = factorial(number);
    printf("\n\nThe factorial of %d is : %d",number,value);
}