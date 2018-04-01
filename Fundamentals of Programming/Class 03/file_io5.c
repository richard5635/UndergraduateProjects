#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fin;
    char str[256];
    int i;
    
    fin=fopen(argv[1], "r");
    if (fin == NULL)
    {
        printf("Cannot open the file.\n");
        exit(1);
    }
    
    while (fgets(str, 256, fin) != NULL)
    {
    for(i=0; str[i] != '\0'; i++)
    {
        if(str[i]>=97 && str[i]<=122) //Range for lowercase letters
        {
            str[i]-=32; //Memory distance between uppercase and lowercase letters in ASCII
        }
        printf("%c", str[i]);
    }
    }
    
    /*while (fgets(str, 256, fin) != NULL)
    {
        printf("%s", str);
    }
    */
    
    fclose(fin);
    
    //fgets
    //
    
    return 0;
}

