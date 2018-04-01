#include <stdio.h>
#include <string.h>
int main(void)
{
char str[100];
 int i;
 int a;
 int b;
 int c;
 char d;
printf ("please input a string:\n");
fgets (str,100, stdin);
 a=strlen(str);
 b=0;
 c=a-1;
 while (b<c){
  d=str[b];
  str[b]=str[c];
  str[c]=d;
   b++;
   c=c-1;
 }
 printf("%s\n",str);
 return 0;
  }
