#include <stdio.h>
#include <stdlib.h>
#define QUEUE_MAX 5

int data[QUEUE_MAX];
int queue_head = 0;
int queue_tail = 0;

void enqueue( int value ){
  if( (queue_tail+1)%(QUEUE_MAX+1) == queue_head ){
    printf( "queue: no more space in queue buffer\n" );
    exit( 1 );
  }
  data[queue_tail] = value;
  queue_tail = (queue_tail+1)%(QUEUE_MAX+1);
}

int dequeue( void ){
  int x;
  if( queue_head == queue_tail ){
    printf( "queue: empty\n" );
    exit( 1 );
  }
  x = data[queue_head];
  queue_head = (queue_head+1)%(QUEUE_MAX+1);
  return x;
}

int main(){
  int op=0, value;
  
  while( op != 3 ){
    printf( "Select (1:enqueue, 2:dequeue, 3:quit)>> " );
    scanf( "%d", &op );
    if( op == 1 ){
      printf( " value >> " );
      scanf( "%d", &value );
      enqueue( value );
    } else if( op == 2 ){
      value = dequeue();
      printf( " value = %d\n", value );
    }
  }

  return 0;
}
