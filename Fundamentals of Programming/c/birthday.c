#include <stdio.h>
int main(void)
{
  int year;
  int month;
  int day;
  

  printf("input year");
  scanf("%d", & year);
  printf("input month");
  scanf("%d", & month);
  printf("input day");
  scanf("%d", &day);
  
	 printf("year: %d \n", year);
	 printf("month: %d \n", month);
	 printf("day: %d \n", day);
	 printf("birday: %d/%d/%d \n", year, month, day);
	 return 0;
	 }
