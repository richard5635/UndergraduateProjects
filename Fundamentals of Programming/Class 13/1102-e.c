   #include <stdio.h>
   #include <string.h>
   #define MAXSTRING 20
   struct wordlist {
       char word [MAXSTRING];
       struct wordlist * next;
   };
   
   int main(){
      char input[MAXSTRING];
      int i, op, pos;
      struct wordlist *elem, *tmp, *head=NULL, *remove;
      while( 1 ){
          /* show menu*/
          printf( "Select 1:append 2:insert 3:remove 4:quit>> " );
          scanf( "%d", &op );
          if( op == 1 ){ /* append*/
              printf( "word>> " );
              scanf( "%s", input );
              /* make new elem*/
              elem = (struct wordlist*)malloc( sizeof(struct wordlist) );
              strncpy( elem->word, input, MAXSTRING );
              elem->next = NULL;
              /* check whether the list is empty or not*/
              if( head == NULL ){
                  head = elem; //the content of elem structure is copied to head
              } else {
                  for( tmp=head; tmp->next!=NULL; tmp=tmp->next );//the temp will be what its pointing to
                  tmp->next = elem; //The appending occurs here
              }
          } else if( op == 2 ){ /* insert*/
              printf( "where[head=0]?>> " );
              scanf( "%d", &pos );
              printf( "word>> " );
              scanf( "%s", input );
              /* make new elem*/
              elem = (struct wordlist*)malloc( sizeof(struct wordlist) );
              strncpy( elem->word, input, MAXSTRING );
              elem->next = NULL;
              /*  check whether it is the head or not*/
              if( pos == 0 ){
                  elem->next = head;
                  head = elem;
              } else {
                  tmp = head;
                  for( i=1; i<pos; i++ ) tmp=tmp->next; //
                  elem->next = tmp->next;
                  tmp->next = elem;
              }
          } else if( op == 3 ){ /* remove*/
              printf( "where[head=0]?>> " );
              scanf( "%d", &pos );
              /* check whether it is the head or not*/
              if( pos == 0 ){
                  tmp = head->next;
                  free( head );
                  head = tmp;
              } else {
                  tmp = head;
                  for( i=1; i<pos; i++ ) tmp=tmp->next;
                  remove = tmp->next;
                  tmp->next = remove->next;
                  free( remove );
              }
          } else { /* finish*/
              break;
          }
          /* show the content of the list*/
          for( tmp=head; tmp!=NULL; tmp=tmp->next ){
              printf( "%s ", tmp->word );
          }
          printf( "\n" );
      }
      return 0;
  }
