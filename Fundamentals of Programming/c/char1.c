#include <stdio.h>

int main (void)
{
char str[]="Hello";

printf("%s\n", str);
str[1]='i';
str[2]='!';
str[3]='\0';
printf("%s\n", str);

return 0;
}
