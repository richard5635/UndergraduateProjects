#include <stdio.h>
#include <string.h>
#define MAXSTRING 20
struct wordlist
{
	char word [MAXSTRING];
	struct wordlist * next;
};

int main()
{
	int i, op, pos;
	struct wordlist *elem, *tmp, *head=NULL, *remove;
	
	elem=(struct wordlist*)malloc(sizeof(struct wordlist));
	strncpy(elem->word, input, MAXSTRING);
	elem->next = NULL;
	
	if(head == NULL)
	{
		else {
			for( tmp=head;tmp->NULL;tmp=tmp->next);
			tmp->next = elem;
			}
	}
}

	