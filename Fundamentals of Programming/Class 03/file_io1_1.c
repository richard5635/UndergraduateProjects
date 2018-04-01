#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fin;
	char str[256];
	
	fin = fopen(argv[1], "r");
	if (fin==NULL)
	{
		printf("Cannot open the file.\n");
		exit(1);
	}
	
	while (fgets(str, 256, fin) !=NULL)
	{
		printf("%s", str);
	}
	
	fclose(fin);
	
	return 0;
	
}