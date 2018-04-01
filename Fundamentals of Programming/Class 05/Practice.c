#include <stdio.h>
#include <string.h>

struct student
{
    char name[20];
    int eng;
    int math;
};

int main()
{
	struct student a, b, *pa;
    strcpy(a.name, "Frank");
    a.eng = 90;
    a.math = 88;
    
    printf("Name:%s\n",a.name);
    printf("English:%d\n",a.eng);
    printf("Mathematics:%d\n\n",a.math);
    
    b=a;
    printf("Name:%s\n",b.name);
    printf("English:%d\n",b.eng);
    printf("Mathematics:%d\n\n",b.math);
    
    pa=&a;
    strcpy(pa->name,"Thomas");
    pa->eng = 85;
    pa->math = 94;
    printf("Name:%s\n", pa->name);
    printf("English:%d\n", pa->eng);
    printf("Mathematics:%d\n\n",pa->math);

    
    return 0;
}