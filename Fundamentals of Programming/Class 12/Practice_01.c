#include <stdio.h>
#include <string.h>
#define MAXSTRING 20
struct wordlist
{
	char word [MAXSTRING];
	struct wordlist * next;
    //connects to the next address
};

int main()
{
	char input[MAXSTRING];
	int i, op, pos;
	struct wordlist *elem, *tmp, *head=NULL, *remove;
	//Head is empty
	
	while( 1 )
	{
		/* shows the menu */
		printf("Select 1:append 2: insert 3:remove 4:quit>> ");
		scanf("%d", &op);
		
		/*append*/		
		if( op==1 )
		{ 
			printf("word>> ");
            scanf( "%s", input );
			
			/* make new element */
			elem = (struct wordlist*)malloc( sizeof(struct wordlist) );
			strncpy( elem->word, input, MAXSTRING);
			elem->next = NULL;
			
			/* check whether the list is empty */
			if( head == NULL )
			{
				head = elem;
                //If the head is empty, the head will be filled with elem's content
			}
			else 
			{
				for(tmp=head; tmp->next!=NULL; tmp=tmp->next);
				tmp->next = elem;
                
			}
		}
		
		/*insert*/
		else if( op==2 )
		{
			printf("where[head=0]?>> ");
			scanf("%d", &pos );
			printf("word>> ");
			scanf("%s", input);
			
			/*make new element*/
			elem = (struct wordlist*)malloc( sizeof(struct wordlist) );
			strncpy( elem->word, input, MAXSTRING);
			//copy the content from input to elem->word, with MAXSTRING as the limit
			elem->next = NULL;
			
			/*puts the desired word into the head and pushes the other words to the right*/
			if( pos == 0 )
			{
				elem->next = head;
                //the next adresses will contain the content inside the address before it
				head = elem;
                //puts the recently typed word into head
			}
			else 
			{
				tmp = head;
				for(i=1;i<pos;i++)
				tmp=tmp->next;
				elem->next = tmp->next;
				tmp->next = elem;
			}
		}
		
		/*Remove*/
		else if( op == 3 )
		{
			printf("where[head=0]?>> ");
			scanf("%d", &pos);
			
			/* check whether it is the head or not*/
			if( pos == 0 )
			{
				tmp = head->next;
				free( head );
				//related to malloc, to return the assigned memory to head
				head = tmp;
			}
			else 
			{
				tmp = head;
				for( i=1; i<pos; i++)
				tmp=tmp->next;
				remove = tmp->next;
				tmp->next = remove->next;
				free( remove );
			}
		}
		
		/*Finish*/
		else 
		{
			break;
		}
		
		/*shows the content of the list*/
		for( tmp=head; tmp!=NULL; tmp=tmp->next )
		{
			printf("%s ",tmp->word );
		}
		printf("\n");
	}
	return 0;
}
				
				
	