//
//  main.c
//  Homework_07
//
//  Created by Richard Sahala Hartanto on 11/15/13.
//  Copyright (c) 2013 Richard Sahala Hartanto. All rights reserved.
//

#include <stdio.h>
#define N 10000

int main(int argc, const char * argv[])
{
    FILE *datafile;
    int i, size, key, data[N];
    char filename [20];
    int head, mid, tail;
    int num=1;
    
    
    printf ("sorted data file: ");
    scanf("%s", filename);
    
    
    
    datafile = fopen(filename, "r");
    for( i=0; i<N; i++)
    {
        if( fscanf(datafile, "%d", &data[i]) == EOF)
            // reads the integer at the first row initially, then moves on to the second row after fscanf is repeated.
        { break; }
    }
    
    size = i;
    
    printf("Search Key : ");
    scanf("%d", &key);
    
    head = 0;
    tail = size - 1;
    mid = (head+tail)/2;
    
    //mid is used as the comparator for the search
    
    while( head <= tail )
    {
        if ( data[mid] < key )
            head = mid + 1;
            //If the middle value is smaller than key, make head equals to mid added by 1
        else if ( data[mid] == key )
        {
            printf("%d found at location %d.\n", key, mid+1);
            break;
        }
        else 
        {
        	printf("%d:[%d,%d,%d] = (%d,%d,%d)\n",num,head,mid,tail,data[head],data[mid],data[tail]);
        num++;
            tail = mid - 1;
            
        }
        mid = (head + tail)/2;
        //Settles another middle point for the next search sequence
    }
    if ( head > tail )
        printf("Not found! %d is not present in the list.\n", key);
    
    return 0;
}

