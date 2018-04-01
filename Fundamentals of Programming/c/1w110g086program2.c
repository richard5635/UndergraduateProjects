#include<stdio.h>
 int main(void)
 {
 int limit;
 int i;
 int j;
 int k;
 int counter;
 int product;
 printf("Input Upper Limit:");
 scanf("%d",&limit);
 while (limit<3){
 printf("error.please make sure the input is bigger than 2.\n Input Upper Limit:");
 scanf("%d",&limit);
 }
 int prime[limit];
 if (limit>2){
 prime[0]=2;
 printf("prime number less than %d are: %d ",limit,prime[0]);
 }
 j=1;
 for(i=3;i<limit;i++){
 counter=0;
 for(k=2;k<i;k++){
 if (i%k==0){
 counter=1;
 break;
 }
 }
 if (counter==0){
 prime[j]=i;
 printf("%d ",prime[j]);
 j++;
 }
 }
 printf("\n");
 product=1;
 for(i=0;i<j;i++){
   product=product*prime[i];
 }
 printf("the product is: %d\n",product);
 return 0;
 }
