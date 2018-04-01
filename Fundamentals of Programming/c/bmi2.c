#include <stdio.h>
int main(void)
{
  int height;
  int weight;
  double height_m;
  double bmi;


  printf ("input height(cm)>");
  scanf("%d", &height);
 
 printf ("input wieght (kg)>");
  scanf ("%d", &weight);

  
  height_m= height / 100.0;
  bmi= weight/ (height_m * height_m);
  printf("BMI : %f\n", bmi);

  if (bmi < 18.5) {
      printf ("Underweight\n");
    } else if (bmi <25) {
      printf("Normal\n");
    } else if (bmi <30) {
      printf ("Overweight\n");
    } else {
      printf("Obese\n");
    }
  return 0;
}
