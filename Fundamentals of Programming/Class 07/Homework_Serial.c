//The Program that uses Serial Search

#include <stdio.h>

#define N 1000000

int main(){
    FILE *datafile;
    int i, size, key, data[N+1];
    char filename[20];

    printf( "data file: " );
    scanf( "%s", filename );

    datafile = fopen( filename, "r" );

    for( i=0; i<N; i++ ){
        if( fscanf(datafile, "%d", &data[i]) == EOF ){
            break;
        }
    }

    printf( "search key: " );
    scanf( "%d", &key );

    data[i] = key; //Puts the keyword at the very last space in the array.
    size = i + 1;

    i = 0;
    while( 1 ){
        printf( "data[%d] = %d\n", i, data[i] );

        if( data[i] == key ){
            break;
        }
        i++;
    }

    if( i == size-1 ){ //This is when the search tool reaches the very last space in the array, which means the keyword does not exist in the spaces before it.
        printf( "not found\n" );
    } else {
        printf( "found in data[%d] = %d\n", i, data[i] );
    }

    return 0;
}
