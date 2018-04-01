//
//  main.c
//  Homework_07
//
//  Created by Richard Sahala Hartanto on 11/15/13.
//  Copyright (c) 2013 Richard Sahala Hartanto. All rights reserved.
//

#include <stdio.h>
#define N 1000000

int main(int argc, const char * argv[])
{
    FILE *datafile;
    int i, size, key, data[N];
    char filename [20];
    
    
    
    printf ("data file: ");
    scanf("%s", filename);
    
    printf("Insert Keyword : ");
    scanf("%d", &key);
    
    datafile = fopen(filename, "r");
    for( i=0; i<N; i++)
    {
        if( fscanf(datafile, "%d", &data[i]) == EOF)
            // reads the integer at the first row initially, then moves on to the second row after fscanf is repeated.
        { break; }
    }
    
    size = i;
    
    for(i=0;i<N;i++)
    {
        printf("Keyword %d found at %d\n", data[i], i+1);
        if (data[i] == key)
        {
            break;
        }
    }
    
    printf("The number %d is found at location %d\n", key, i+1);
    
    return 0;
}

