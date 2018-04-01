#include <stdio.h>

int main(void)
{
 
  int weight;
 double  height_m;
 double RohrerIndex;

  printf (" input height (cm)>");
  scanf ("%lf", &height_m);

  printf("input weight (kg)>");
  scanf("%d", &weight);

  RohrerIndex= weight/( height_m*height_m *height_m)* 10000000.0;
  printf("Rohrer Index: %f\n", RohrerIndex);

  if (RohrerIndex<100){
    printf("severely underweight\n");
  } else if (RohrerIndex <115) {
    printf("Underweight\n");
  }else if (RohrerIndex<145) {
    printf("normal\n");
  } else if (RohrerIndex<160) {
printf ("Overweight\n");
  } else {
    printf ("Obese\n");
  }


  return 0;
}
