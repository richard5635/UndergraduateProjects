#include <stdio.h>
#include <stdlib.h>
#define STACK_MAX 10

double data[STACK_MAX];
int stack_top = 0;

void stack_push( double value ){
  if( stack_top == STACK_MAX ){
    printf( "stack: overflow\n" );
    exit( 1 );
  }
  data[stack_top] = value;
  stack_top++;
}

double stack_pop( void ){
  if( stack_top == 0 ){
    printf( "stack: underflow\n" );
    exit( 1 );
  }
  stack_top--;
  return data[stack_top];
}

int main(){
  char buf[10];
  double x, y, ans;

  while( buf[0] != '=' ){
    printf( ">> " );
    scanf( "%s", buf );

    if( buf[0] == '+' ){
      y = stack_pop();
      x = stack_pop();
      stack_push( x + y );
    } else if( buf[0] == '-' ){
      y = stack_pop();
      x = stack_pop();
      stack_push( x - y );
    } else if( buf[0] == '*' ){
      y = stack_pop();
      x = stack_pop();
      stack_push( x * y );
    } else if( buf[0] == '/' ){
      y = stack_pop();
      x = stack_pop();
      stack_push( x / y );
    } else if( buf[0] == '=' ){
      ans = stack_pop();
    } else {
      x = atof( buf );
      stack_push( x );
    }
  }

  printf( "answer = %f\n", ans );

  return 0;
}
